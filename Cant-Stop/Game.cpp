//
//  Game.cpp
//  P4-Shackett
//
//  Created by Alec Shackett on 2/23/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include "Game.hpp"

//----------------------------------------------------------------------------
Game::
Game() {
    srand( (int) time( NULL ) );
    getPlayers( NPLAYERS );
    dSet = new FakeDice;
}

//----------------------------------------------------------------------------
void Game::
getPlayers( int num ) {
    bool success;
    bool taken[5] = {};
    
    Player* p;
    Player::instructions( cout );
    for( ; Player::created() < 4; ) {
        success = false;
        try {
            cout <<"Colors available: ";
            for( int x = 1; x <= 4; ++x ) if( !taken[x] ) cout <<colors[x] <<" ";
            
            cout <<"\nEnter a player (name, color): ";
            p = new Player( cin );
            
            //Checks if the name/color is in use.
            bool nInUse = CL.checkName( p->name() );
            bool cInUse = CL.checkColor( p->color() );
            string inName = p->name();
            char inColor = colors[p->color()][0];
            if( nInUse && cInUse ) throw BadPlayer( inName, inColor );
            if( nInUse ) throw BadName( inName, inColor );
            if( cInUse ) throw BadColor( inName, inColor );
            
            taken[p->color()] = true;
            
            //No exception - we have a good player.
            success = true;
            cout << "  Player successfully added.\n\n";
        }
        catch( EndEntering& e ) { e.print(); break; }
        catch( BadPlayer& bp ) { bp.print(); }
        catch( bad_alloc bp ) {
            cerr <<"  Allocation error for player #" <<Player::created() <<".\n";
            exit( 1 );
        }
        if( !success ) delete p;
        else CL.insertBack( p );
    }
}

//----------------------------------------------------------------------------
void Game::
play() {
    if( CL.empty() ) gameState = quit;
    else oneTurn( CL.first() );
    
    for(;;) {
        if( gameState == quit || gameState == done ) break;
        if( CL.empty() ) gameState = quit;
        else oneTurn( CL.next() );
    }
    
    if( !CL.empty() ) {
        Player* Head = CL.first();
        Player* Current = Head;
        cout <<endl;
        for(;;) {
            cout <<"Updating " <<Current->name() <<endl;
            sb.update( Current->name(), Current->score(), Current->captured() );
            Current = CL.next();
            if( Current == Head ) break;
        }
    }
}

//----------------------------------------------------------------------------
void Game::
oneTurn( Player *p ) {
    b.startTurn( p );
    cout <<*p <<endl;
    
    bool turnDone = false;
    char ch;
    //Menu
    for(;;) {
        if( turnDone ) break;
        
        bool success, badCh;
        for(;;) {
            success = false;
            badCh = false;
            try {
                cout <<LINE <<"\nDo you want to:\n"
                <<"(R)oll?\n" <<"(S)top?\n" <<"(D)isplay Scoreboard?\n"
                <<"(Q)uit?\n";
                
                cin >>ch;
                cin.ignore( 1000, '\n' );
                
                switch ( toupper( ch ) ) {
                    case 'D': cout <<endl <<sb <<endl; break;
                    case 'R': turnDone = doRoll(); break;
                    case 'S': turnDone = doStop( p ); break;
                    case 'Q': turnDone = doQuit( p ); break;
                    default: badCh = true; break;
                }
                
                if( badCh ) throw BadChoice( ch );
                success = true;
            }
            catch ( BadChoice& bs ) { bs.print(); }
            if( success ) break;
        }
    }
}

//----------------------------------------------------------------------------
bool Game::
doRoll() {
    const int* values = dSet->roll();
    
    bool l = b.move( values[0] );
    bool r = b.move( values[1] );
    
    if( !l && !r ) {
        b.bust();
        cout <<b <<endl <<BUST <<endl;
        return true;
    }

    cout <<b <<endl;
    return false;
}

//----------------------------------------------------------------------------
bool Game::
doStop( Player* p ) {
    gameState = b.stop();
    cout <<b <<endl;
    cout <<STOP <<endl;
    if( gameState == done ) cout <<p->name() <<" has won!\n";
    return true;
}

//----------------------------------------------------------------------------
bool Game::
doQuit( Player* p ) {
    gameState = b.stop();
    sb.update( p->name(), p->score(), p->captured() );
    CL.remove();
    cout <<endl <<QUIT <<endl;
    return true;
}

//----------------------------------------------------------------------------

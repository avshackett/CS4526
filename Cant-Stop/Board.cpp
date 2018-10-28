//
//  Board.cpp
//  P6-Shackett
//
//  Created by Alec Shackett on 3/8/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include "Board.hpp"

//----------------------------------------------------------------------------
//Constructor
Board::
Board() { for( int x = 2; x < 13; ++x ) backBone[x] = new Column( x ); }

//----------------------------------------------------------------------------
//Prints out the 11 columns.
ostream& Board::
print( ostream& out ) {
    cout <<"\n";
    for( int x = 2; x < 13; ++x ) backBone[x]->print( out );
    return out;
}

//----------------------------------------------------------------------------
//Begins the turn for a player and stores a pointer to the current player.
void Board::
startTurn( Player* p ) {
    curPlayer = p;
    inUse = 0;
    for( int x = 0; x < 3; ++x ) used[x] = 0;
}

//----------------------------------------------------------------------------
//Calls the columns move function which will return true if the move was done.
//If there is no tower in the column, or it is not available, the board move
//function will check if it has another tower available and then place it on
//the specified tower.
bool Board::
move( int col ) {
    bool result = ++*backBone[col];
    //bool result = backBone[col]->move();
    if( !result && inUse < 3 ) {
        backBone[col]->startTower( curPlayer );
        used[inUse++] = col;
        result = true;
    }
    return result;
}

//----------------------------------------------------------------------------
//Replaces towers with the player's color and clears the current player pointer.
GStatus Board::
stop() {
    bool won = false;
    for( int x = 0; x < inUse; ++x ) {
        won = backBone[used[x]]->stop( curPlayer );
    }
    
    curPlayer = nullptr;
    
    if( won ) return done;
    else return begun;
}

//----------------------------------------------------------------------------
//Clears the board without saving any tower positions.
void Board::
bust() { for( int x = 0; x < inUse; ++x ) backBone[used[x]]->bust(); }

//----------------------------------------------------------------------------

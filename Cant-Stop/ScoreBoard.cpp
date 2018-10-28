//
//  ScoreBoard.cpp
//  P11-Shackett
//
//  Created by Alec Shackett on 3/15/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include "ScoreBoard.hpp"

//----------------------------------------------------------------------------
ScoreBoard::
ScoreBoard() {
    insert( SBPair( "Game", Score() ) );
    realize();
}

//----------------------------------------------------------------------------
void ScoreBoard::
realize() {
    ifstream inFile( INF );
    if( !inFile.is_open() ) fatal( "Failed to open " INF " for input." );
    
    for(;;) {
        Score s;
        string name;
        inFile >>name;
        if( inFile.eof() ) break;
        s.realize( inFile );
        if( find( name ) != end() ) find( name )->second = s;
        insert( SBPair( name, s ) );
    }
}

//----------------------------------------------------------------------------
void ScoreBoard::
serialize() {
    ofstream outFile( OUTF );
    if( !outFile.is_open() ) fatal( "Failed to open " OUTF " for output." );
    
    SBoard::iterator itr;
    for ( itr = begin(); itr != end(); ++itr ) {
        outFile <<itr->first;
        itr->second.serialize( outFile );
    }
}

//----------------------------------------------------------------------------
ostream& ScoreBoard::
print( ostream& out ) {
    SBoard::iterator itr;
    for ( itr = begin(); itr != end(); ++itr ) {
        out <<itr->first
        <<itr->second;
    }
    return out;
}

//----------------------------------------------------------------------------
void ScoreBoard::
update( const string name, const int cols, const int* cap ) {
    
    SBoard::iterator itr = find( "Game" );
    itr->second.update( cols, cap );
    
    itr = find( name );
    if( itr != end() ) {
        itr->second.update( cols, cap );
    }
    else {
        Score s;
        s.update( cols, cap );
        insert( SBPair( name, s ) );
    }
}

//----------------------------------------------------------------------------

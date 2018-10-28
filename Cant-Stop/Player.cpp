//
//  Player.cpp
//  P2-Shackett
//
//  Created by Alec Shackett on 2/7/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include "Player.hpp"

int Player::_created = 0;

//----------------------------------------------------------------------------
//Constructor
Player::
Player( istream& sin ) throw ( BadPlayer, BadName, BadColor, EndEntering ) {
    string inName;
    char inColor;
    bool skip = false;
    
    sin >>inName;
    if( inName == "/" ) skip = true;
    if( !skip ) {
        sin >>inColor;
        cin.ignore( 1000, '\n' );
        
        if ( !sin.good() ) throw "Low level read error\n";
        
        bool badName = false;
        if( inName.find( ' ' ) != -1 ) badName = true;
        else _name = inName;
        
        switch( toupper( inColor ) ) {
            case 'O': _color = orange;  break;
            case 'Y': _color = yellow;  break;
            case 'G': _color = green;   break;
            case 'B': _color = blue;    break;
            default : _color = error;   break;
        };
        
        if( badName && _color == error ) throw BadPlayer( inName, inColor );
        if( badName ) throw BadName( inName, inColor );
        if( _color == error ) throw BadColor( inName, inColor );
    }
    if( skip ) throw EndEntering();
    
    ++_created;
}

//----------------------------------------------------------------------------
//Prints out what is required input to construct a player.
void Player::
instructions( ostream& out ) {
    out <<"Please enter 4 players.\n"
    <<"Names include no spaces and have to be unused.\n"
    <<"Color choices are (O)range, (Y)ellow, (G)reen, (B)lue.\n"
    <<"Enter \"/\" to start with less than 4 players.\n"
    <<"----------------------------------------------------------------\n\n";
}

//----------------------------------------------------------------------------
//Prints out the player's name, color, score, and captured columns.
ostream& Player::
print( ostream& out ) {
    out <<"\nTURN START------------------------------------------------------\n"
    <<_name << " " << colors[_color] << " Score: " << _score << " Cap: ";
    for( int x = 0; x < 3; x++ ) out << _captured[x] << " ";
    out <<"\n";
    return out;
}

//----------------------------------------------------------------------------
//Adds a column to the player's list of won columns.
bool Player::
wonColumn( int colNum ) {
    _captured[_score++] = colNum;
    return ( _score == 3 );
}

//----------------------------------------------------------------------------

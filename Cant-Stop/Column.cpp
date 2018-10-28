//
//  Column.cpp
//  P3-Shackett
//
//  Created by Alec Shackett on 2/14/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include "Column.hpp"

const int Column::lengths[13] = { 0,0,3,5,7,9,11,13,11,9,7,5,3 };

//----------------------------------------------------------------------------
//Places a tower at player's previous color. If not, then at position 1.
bool Column::
startTower( Player* p ) {
    if( marker[white] == 0  && _state == available ){
        if( marker[p->color()] > 0 ) marker[white] = marker[p->color()];
        else marker[white] = 1;
        return true;
    }
    else return false;
}

//----------------------------------------------------------------------------
//If there is a tower on the column, move it forward 1 position and return true.
//If the column is won, set the column state to pending and return true.
//If there is no tower on the column and/or it is pending/captured return false.
bool Column::
move() {
    if( marker[white] == 0 || _state != available ) return false;
    marker[white]++;
    if( marker[white] == len ) _state = pending;
    return true;
}

//----------------------------------------------------------------------------
//Replace towers with the player's color and return the state of the column.
bool Column::
stop( Player* p ) {
    marker[p->color()] = marker[white];
    marker[white] = 0;
    if( _state == pending ){
        _state = captured;
        return p->wonColumn( col );
    }
    return false;
}

//----------------------------------------------------------------------------
//Clear all towers and save no positions.
void Column::
bust() {
    marker[white] = 0;
    _state = available;
}

//----------------------------------------------------------------------------
//Print out the column with its number, state, and tower/player positions.
ostream& Column::
print( ostream& out ) {
    out <<setw(3) <<col <<" " <<setw( 11 ) <<states[_state] <<" ";
    
    for( int x = 1; x <= len; ++x ) {
        string line = { "-----" };
        if( marker[white] == x ) line[white] = 'T';
        if( marker[orange] == x ) line[orange] = 'O';
        if( marker[yellow] == x ) line[yellow] = 'Y';
        if( marker[green] == x ) line[green] = 'G';
        if( marker[blue] == x ) line[blue] = 'B';
        out <<"|" <<line;
    }
    out <<"|" <<endl;
    
    return out;
}

//----------------------------------------------------------------------------

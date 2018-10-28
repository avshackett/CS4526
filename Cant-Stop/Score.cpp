//
//  Score.cpp
//  P11-Shackett
//
//  Created by Alec Shackett on 3/15/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include "Score.hpp"

//----------------------------------------------------------------------------
void Score::
serialize( ostream& out ) {
    for( int x = 0; x < 13; ++x ) out <<" " <<scores[x];
    out <<"\n";
}

//----------------------------------------------------------------------------
void Score::
realize( istream& in ) {
    for( int x = 0; x < 13; ++x ) in >>scores[x];
}

//----------------------------------------------------------------------------
ostream& Score::
print( ostream& out ) {
    out <<" | Played: " <<scores[0];
    out <<" | Won: " <<scores[1] << " | ";
    for( int x = 2; x < 13; ++x ) out <<scores[x] << " ";
    out <<"\n";
    return out;
}

//----------------------------------------------------------------------------
void Score::
update( int cols, const int *captured ) {
    ++scores[0];
    if( cols == 3 ) ++scores[1];
    for( int x = 0; x < cols; ++x ) ++scores[captured[x]];
}

//----------------------------------------------------------------------------

//
//  Column.hpp
//  P3-Shackett
//
//  Created by Alec Shackett on 2/14/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef Column_hpp
#define Column_hpp

#include <iomanip>
#include "tools.hpp"
#include "enums.hpp"
#include "Player.hpp"

extern string states[3];

//----------------------------------------------------------------------------
class Column{
    static const int lengths[13];
    int marker[5] = { 0 };
    CStates _state;
    int col;
    int len;
public:
    Column( int col ) : col( col ), _state( available ), len( lengths[col] ) { }
    ~Column() { }
    ostream& print( ostream& out );
    CStates state() { return _state; }
    bool startTower( Player* p );
    bool move();
    bool stop( Player* p );
    void bust();
    bool operator++() { return move(); }
};

//----------------------------------------------------------------------------
inline ostream& operator <<( ostream& out, Column& c ) {return c.print( out );}

#endif /* Column_hpp */

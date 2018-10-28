//
//  Player.hpp
//  P2-Shackett
//
//  Created by Alec Shackett on 2/7/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "tools.hpp"
#include "enums.hpp"
#include "Bad.hpp"

extern string colors[6];

//----------------------------------------------------------------------------
class Player {
private:
    string _name;
    Color _color;
    int _score = 0;
    int _captured[3] = { };
    static int _created;
public:
    Player( istream& sin ) throw( BadPlayer, BadName, BadColor, EndEntering );
    ~Player() { --_created; }
    ostream& print( ostream& out );
    string name() { return _name; }
    Color color() { return _color; }
    int score() { return _score; }
    const int* captured() { return _captured; }
    static const int created() { return _created; }
    bool wonColumn( int colNum );
    static void instructions( ostream& out );
};

//----------------------------------------------------------------------------
inline ostream& operator <<( ostream& out, Player& p ) {return p.print( out );}

#endif /* Player_hpp */

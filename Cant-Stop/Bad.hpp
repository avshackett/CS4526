//
//  BadPlayer.hpp
//  P10-Shackett
//
//  Created by Alec Shackett on 3/13/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef BadPlayer_hpp
#define BadPlayer_hpp

#include "tools.hpp"

//--------------------------------Player Check--------------------------------
//----------------------------------------------------------------------------
class BadPlayer {
public:
    string name;
    char color;
    
    BadPlayer( string name, char color ) : name( name ), color( color ) { }
    
    virtual void print() {
        cerr <<"  Both name and color are wrong.\n"
        <<"  Legal names include no spaces and have to be unused.\n"
        <<"  Color choices are O Y G B.\n";
        pr();
    }
    
    void pr() {
        cerr <<"  You entered \"" <<name <<"\" and \"" <<color <<"\" .\n  Please retry.\n";
    }
};

//----------------------------------------------------------------------------
class BadName : public BadPlayer {
public:
    BadName( string name, char color ) : BadPlayer( name, color ) { }
    virtual void print() {
        cerr <<"  Legal names include no spaces and have to be unused.\n";
        pr();
    }
};

//----------------------------------------------------------------------------
class BadColor : public BadPlayer {
public:
    BadColor( string name, char color ) : BadPlayer( name, color ) { }
    virtual void print() {
        cerr <<"  Color choices are O Y G B.\n";
        pr();
    }
};

//----------------------------------------------------------------------------

//------------------------------Paring Check----------------------------------
//----------------------------------------------------------------------------
class BadPairs {
public:
    char p1, p2;
    
    BadPairs( char p1, char p2 ) : p1( p1 ), p2( p2 ) { }
    
    virtual void print() {
        cerr <<"  Both pairs are wrong.\n"
        <<"  Pair choices are A B C D.\n";
        pr();
    }
    
    void pr() {
        cerr <<"  You entered \"" <<p1 <<"\" and \"" <<p2 <<"\" .\n  Please retry.\n";
    }
};

//----------------------------------------------------------------------------
class BadPair1 : public BadPairs {
public:
    BadPair1( char p1, char p2 ) : BadPairs( p1, p2 ) { }
    
    virtual void print() {
        cerr <<"  Pair 1 is wrong.\n"
        <<"  Pair choices are A B C D.\n";
        pr();
    }
};

//----------------------------------------------------------------------------
class BadPair2 : public BadPairs {
public:
    BadPair2( char p1, char p2 ) : BadPairs( p1, p2 ) { }
    
    virtual void print() {
        cerr <<"  Pair 2 is wrong.\n"
        <<"  Pair choices are A B C D.\n";
        pr();
    }
};

//----------------------------------------------------------------------------


//-------------------------------Choice check---------------------------------
//----------------------------------------------------------------------------
class BadChoice {
public:
    char choice;
    
    BadChoice( char choice ) : choice( choice ) { }
    
    virtual void print() {
        cerr <<"  Incorrect choice.\n"
        <<"  Turn choices are D R S Q.\n";
        pr();
    }
    
    void pr() {
        cerr <<"  You entered \"" <<choice <<"\".\n  Please retry.\n";
    }
};

//----------------------------------------------------------------------------


//-------------------------------End Entering---------------------------------
//----------------------------------------------------------------------------
class EndEntering {
public:
    EndEntering() { }
    
    virtual void print() {
        cerr <<"Done entering players.\n";
    }
};

//----------------------------------------------------------------------------

#endif /* BadPlayer_hpp */

//
//  Dice.hpp
//  P1-Shackett
//
//  Created by Alec Shackett on 1/27/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef Dice_hpp
#define Dice_hpp

#define IN "rolls.txt"

#include <iomanip>
#include <fstream>
#include "Bad.hpp"
#include "tools.hpp"

//----------------------------------------------------------------------------
class Dice {
    int nDice;
    int* values;
public:
    Dice( int n = 6 ) : nDice( n ) { values = new int[nDice]; roll(); }
    virtual ~Dice() { delete[] values; }
    virtual ostream& print( ostream& out );
    virtual const int* roll();
};

//----------------------------------------------------------------------------
class CantStopDice : public Dice {
protected:
    int* totals;
public:
    CantStopDice() : Dice( 4 ) { totals = new int[2] { }; }
    virtual ~CantStopDice() { delete[] totals; }
    ostream& print( ostream& out );
    virtual const int* roll();
};

//----------------------------------------------------------------------------
class FakeDice : public CantStopDice {
private:
    ifstream input;
public:
    FakeDice();
    virtual ~FakeDice() { input.close(); };
    const int* roll();
};

//----------------------------------------------------------------------------
inline ostream& operator <<( ostream& out, Dice& d ) {return d.print( out );}
inline ostream& operator <<(ostream& out,CantStopDice& d){return d.print(out);}

#endif /* Dice_hpp */

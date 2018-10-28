//
//  Dice.cpp
//  P1-Shackett
//
//  Created by Alec Shackett on 1/27/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include "Dice.hpp"


//----------------------------------------------------------------------------
/*
Dice::
Dice( int n ) : nDice( n ) {
    values = new int[nDice];
    roll();
}
*/
//------------------------------------Dice------------------------------------
//----------------------------------------------------------------------------
//Print out the dice values.
ostream& Dice::
print( ostream& out ) {
    for( int x = 0; x < nDice; x++ ) out << values[x] << " ";
    return out;
}

//----------------------------------------------------------------------------
//Compute random values for the dice.
const int* Dice::
roll() {
    for( int x = 0; x < nDice; x++ ) values[x] = ( rand() % 6 ) + 1;
    return values;
}

//--------------------------------CantStopDice--------------------------------
//----------------------------------------------------------------------------
//Prints out the two pairs of dice.
ostream& CantStopDice::
print( ostream& out ) {
    out <<"\nFirst pair: " <<totals[0]
    <<"\nSecond pair: " <<totals[1] <<endl;
    return out;
}

//----------------------------------------------------------------------------
//Computes random values for the dice and then asks for pairings.
const int* CantStopDice::
roll() {
    const int* vals = Dice::roll();
    char choice = 'a', inP1, inP2;
    int selected[2];
    bool success, badP1, badP2;
    
    for( int x = 0; x < 4; ++x ) cout <<"(" <<choice++ <<") " <<vals[x] <<endl;
    cout <<endl;
    
    for(;;) {
        badP1 = false;
        badP2 = false;
        success = false;
        try {
            cout <<"Input first pair:\n";
            cin >>inP1 >>inP2;
            cin.ignore( 1000, '\n' );
            inP1 = toupper( inP1 );
            inP2 = toupper( inP2 );
            
            switch ( inP1 ) {
                case 'A': selected[0] = vals[0]; break;
                case 'B': selected[0] = vals[1]; break;
                case 'C': selected[0] = vals[2]; break;
                case 'D': selected[0] = vals[3]; break;
                default: badP1 = true; break;
            }
            
            switch ( inP2 ) {
                case 'A': selected[1] = vals[0]; break;
                case 'B': selected[1] = vals[1]; break;
                case 'C': selected[1] = vals[2]; break;
                case 'D': selected[1] = vals[3]; break;
                default: badP2 = true; break;
            }
            
            if( badP1 && badP2 ) throw BadPairs( inP1, inP2 );
            if( inP1 == inP2 ) throw BadPairs( inP1, inP2 );
            if( badP1 ) throw BadPair1( inP1, inP2 );
            if( badP2 ) throw BadPair2( inP1, inP2 );
            
            totals[0] = selected[0] + selected[1];
            totals[1] = vals[0] + vals[1] + vals[2] + vals[3] - totals[0];
            success = true;
        }
        catch ( BadPairs& bs) { bs.print(); }
        if( success ) break;
    }
    return totals;
}

//----------------------------------FakeDice----------------------------------
//----------------------------------------------------------------------------
//Constructor
FakeDice::
FakeDice() : input( IN ) {
    if( !input.is_open() ) fatal( "Failed to open IN for dice input." );
}

//----------------------------------------------------------------------------
//Read in 4 values and make two pairs.
const int* FakeDice::
roll() {
    print( cout );
    int a, b, c, d;
    input >>a >>b >>c >>d;
    if( input.eof() ) fatal( "End of dice input file." );
    cout <<a <<" " <<b <<" " <<c <<" " <<d <<endl;
    totals[0] = a + b;
    totals[1] = c + d;
    return totals;
}
//----------------------------------------------------------------------------

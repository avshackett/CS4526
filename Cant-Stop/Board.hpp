//
//  Board.hpp
//  P6-Shackett
//
//  Created by Alec Shackett on 3/8/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "Column.hpp"

//----------------------------------------------------------------------------
class Board {
private:
    int inUse = 0;
    int used[3] = { };
    Column* backBone[13] = { nullptr, nullptr };
    Player* curPlayer = nullptr;
public:
    Board();
    ~Board() { for( int x = 0; x < 13; ++x ) delete backBone[x]; }
    ostream& print( ostream& out );
    void startTurn( Player* p );
    bool move( int col );
    GStatus stop();
    void bust();
};

//----------------------------------------------------------------------------
inline ostream& operator <<( ostream& out, Board& b ) {return b.print( out );}

#endif /* Board_hpp */

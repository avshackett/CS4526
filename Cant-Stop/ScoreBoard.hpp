//
//  ScoreBoard.hpp
//  P11-Shackett
//
//  Created by Alec Shackett on 3/15/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef ScoreBoard_hpp
#define ScoreBoard_hpp

#define SBoard  map<string, Score>
#define SBPair  pair<string, Score>
#define INF "scoreboard.txt"
#define OUTF "outboard.txt"

#include <map>
#include <fstream>
#include "tools.hpp"
#include "Score.hpp"

class ScoreBoard : public SBoard {
private:
public:
    ScoreBoard();
    ~ScoreBoard() { serialize(); }
    void realize();
    void serialize();
    ostream& print( ostream& out );
    void update( const string name, const int cols, const int* cap );
};

//----------------------------------------------------------------------------
inline ostream& operator <<( ostream& out, ScoreBoard& s ) {return s.print( out );}

#endif /* ScoreBoard_hpp */

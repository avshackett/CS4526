//
//  Game.hpp
//  P4-Shackett
//
//  Created by Alec Shackett on 2/23/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#define NPLAYERS 4
#define LINE "----------------------------------------------------------------"
#define STOP "------------------------------STOP------------------------------"
#define BUST "------------------------------BUST------------------------------"
#define QUIT "------------------------------QUIT------------------------------"

#include "Dice.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "CList.hpp"
#include "Bad.hpp"
#include "ScoreBoard.hpp"

extern string colors[6];

//----------------------------------------------------------------------------
class Game {
private:
    Dice* dSet = nullptr;
    CList<Player> CL;
    Board b;
    ScoreBoard sb;
    const int* curValues = nullptr;
    GStatus gameState = begun;
//Functions
    void getPlayers( int numPlayers );
    void oneTurn( Player* p );
    bool doRoll();
    bool doStop( Player* p );
    bool doQuit( Player* p );
public:
    Game();
    ~Game() { delete dSet; }
    void play();
};

#endif /* Game_hpp */


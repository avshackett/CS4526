//
//  main.cpp
//  P3-Shackett
//
//  Created by Alec Shackett on 2/14/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

int main() {
    try {
        banner();
        Game* g = new Game;
        g->play();
	delete g;
        bye();
    }
    catch(...) {
        cerr <<"  Last-ditch effort to catch exceptions.\n";
    }
}

CXX = g++

CXXFLAGS = -std=c++11 -Wall -g

OBJ = main.o tools.o Board.o Column.o Dice.o enums.o Game.o Player.o Score.o ScoreBoard.o

CantStop: $(OBJ)
	g++ $(CXXFLAGS) -o CantStop $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) CantStop

#	g++ -MM *.cpp >>Makefile

Board.o: Board.cpp Board.hpp Column.hpp tools.hpp enums.hpp Player.hpp \
  Bad.hpp
Column.o: Column.cpp Column.hpp tools.hpp enums.hpp Player.hpp Bad.hpp
Dice.o: Dice.cpp Dice.hpp Bad.hpp tools.hpp
Game.o: Game.cpp Game.hpp Dice.hpp Bad.hpp tools.hpp Player.hpp enums.hpp \
  Board.hpp Column.hpp CList.hpp ScoreBoard.hpp Score.hpp
Player.o: Player.cpp Player.hpp tools.hpp enums.hpp Bad.hpp
Score.o: Score.cpp Score.hpp tools.hpp
ScoreBoard.o: ScoreBoard.cpp ScoreBoard.hpp tools.hpp Score.hpp
enums.o: enums.cpp enums.hpp
main.o: main.cpp Game.hpp Dice.hpp Bad.hpp tools.hpp Player.hpp enums.hpp \
  Board.hpp Column.hpp CList.hpp ScoreBoard.hpp Score.hpp
tools.o: tools.cpp tools.hpp

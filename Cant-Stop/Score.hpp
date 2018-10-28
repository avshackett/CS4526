//
//  Score.hpp
//  P11-Shackett
//
//  Created by Alec Shackett on 3/15/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp

#include <iomanip>
#include "tools.hpp"

class Score {
private:
    int scores[13] = { };
    
public:
    Score() = default;
    ~Score() { };
    ostream& print( ostream& out );
    void update( int cols, const int* captured );
    void serialize( ostream& out );
    void realize( istream& in );
};

//----------------------------------------------------------------------------
inline ostream& operator <<( ostream& out, Score& s ) {return s.print( out );}

#endif /* Score_hpp */

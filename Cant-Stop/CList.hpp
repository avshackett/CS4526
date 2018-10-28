//
//  CList.hpp
//  P7-Shackett
//
//  Created by Alec Shackett on 3/12/18.
//  Copyright © 2018 Alec Shackett. All rights reserved.
//

#ifndef CList_hpp
#define CList_hpp

#include "tools.hpp"
#include "enums.hpp"
//#include "Player.hpp"

//----------------------------------------------------------------------------
template <class BT> class CList;

//----------------------------------------------------------------------------
template <class BT>
class Cell {
    friend class CList<BT>;
private:
    BT* p;
    Cell<BT>* next;
public:
    Cell( BT* p, Cell* c ) : p( p ), next( c ) { }
    ~Cell() { delete p; }
};

//----------------------------------------------------------------------------
template <class BT>
class CList {
private:
    int players = 0;
    Cell<BT>* Head = nullptr;
    Cell<BT>* Tail = nullptr;
    Cell<BT>* Current = nullptr;
public:
    CList() = default;
    ~CList();
    int count() { return players; }
    bool empty() { return ( players < 1 ); }
    ostream& print( ostream& out );
    void insertBack( BT* p );
    BT* first();
    BT* next();
    void remove();
    bool checkName( string name );
    bool checkColor( Color color );
};

//----------------------------------------------------------------------------
template <class BT> inline ostream& operator <<( ostream& out, CList<BT>& c ) {return c.print( out );}

//----------------------------------------------------------------------------
//Destructor
template <class BT> CList<BT>::
~CList() {
    if( !empty() ) {
        Cell<BT>* scan = Head;
        for(;;) {
            if( empty() ) break;
            Cell<BT>* temp = scan->next;
            cout <<"Deleting: " <<scan->p->name() <<endl;
            scan->next = nullptr;
            delete scan;
            --players;
            scan = temp;
        }
    }
}

//----------------------------------------------------------------------------
//Prints out the linked list.
template <class BT> ostream& CList<BT>::
print( ostream& out ){
    if( empty() ){
        cout <<"Player list is empty!" <<endl;
    }
    else {
        Cell<BT>* scan = Head;
        for(;;) {
            out <<scan->p->name() <<endl;
            scan = scan->next;
            if( scan == Head ) break;
        }
    }
    out <<"Done printing." <<endl;
    return out;
}

//----------------------------------------------------------------------------
//Inserts a new player into the back of the list.
template <class BT> void CList<BT>::
insertBack( BT* p ) {
    if( empty() ) {
        Head = new Cell<BT>( p, nullptr );
        Tail = Head;
        Head->next = Head;
    }
    else {
        Tail->next = new Cell<BT>( p, Head );
        Tail = Tail->next;
    }
    ++players;
}

//----------------------------------------------------------------------------
//Sets the Current pointer to the first player in the linked list.
template <class BT> BT* CList<BT>::
first() {
    if( empty() ){
        cout <<"Player list is empty!" <<endl;
        return nullptr;
    }
    Current = Head;
    return Current->p;
}

//----------------------------------------------------------------------------
//Sets the Current pointer to the next player in the linked list.
template <class BT> BT* CList<BT>::
next() {
    if( empty() ){
        cout <<"Player list is empty!" <<endl;
        return nullptr;
    }
    Current = Current->next;
    return Current->p;
}

//----------------------------------------------------------------------------
//Removes the player at the Current pointer. Shifts Current to the next player.
template <class BT> void CList<BT>::
remove() {
    if( empty() ){
        cout <<"Can't remove. Player list is empty!" <<endl;
        return;
    }
    
    Cell<BT>* scan = Head;
    Cell<BT>* prev = Tail;
    
    for(;;) {
        if( scan == Current ) {
            bool isHead = false, isTail = false;
            Cell<BT>* next = Current->next;
            
            if( Current == Head ) isHead = true;
            if( Current == Tail ) isTail = true;
            Current->next = nullptr;
            delete Current;
            
            Current = prev;
            prev->next = next;
            
            if( isHead ) {
                Head = next;
                Tail->next = Head;
            }
            else if( isTail ) Tail = prev;
            
            break;
        }
        else{
            prev = scan;
            scan = scan->next;
        }
    }
    --players;
}

//----------------------------------------------------------------------------
//Returns false if name not in use.
template <class BT> bool CList<BT>::
checkName( string name ) {
    if( empty() ) return false;
    else {
        Cell<BT>* scan = Head;
        for(;;) {
            string lName = scan->p->name();
            string iName = name;
            
            int x;
            for( x = 0; x < lName.size(); ++x ) lName[x] = tolower( lName[x] );
            for( x = 0; x < iName.size(); ++x ) iName[x] = tolower( iName[x] );
            
            if( lName == iName ) {
                return true;
            }
            scan = scan->next;
            if( scan == Head ) break;
        }
        return false;
    }
}

//----------------------------------------------------------------------------
//Returns false if color not in use.
template <class BT> bool CList<BT>::
checkColor( Color color ) {
    if( empty() ) return false;
    else {
        Cell<BT>* scan = Head;
        for(;;) {
            if( scan->p->color() == color ) {
                return true;
            }
            scan = scan->next;
            if( scan == Head ) break;
        }
        return false;
    }
}

//----------------------------------------------------------------------------


#endif /* CList_hpp */

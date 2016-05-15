//
//  LinkedList.h
//  DataStructsAndAlgos
//
//  Created by Nicolas Audren on 14/05/2016.
//  Copyright © 2016 Nicosoft. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h


#define DEBUG_LINKEDLIST 1


// LinkedList declaration

template <class T>
class LinkedList
{
    struct Node
    {
    public:
        
        T value;
        Node* next = nullptr;
    };
    
public:
    
    // constructor & destructor
    LinkedList();
    ~LinkedList();
    
    // capacity
    bool isEmpty() const;
    int getCount() const;
   
    // insertion
    void pushFront( T _value );
    void pushEnd( T _value );
    void insertAfter( T _value, T _after);
    
    // deletion
    bool popFront();
    bool popEnd();
#ifdef DEBUG_LINKEDLIST
    // utilities
    void printSelf();
#endif
    // data
    Node* first = nullptr;
};


#include "LinkedList.cpp"



#endif /* LinkedList_h */

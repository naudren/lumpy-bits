//
//  LinkedListTests.cpp
//  DataStructsAndAlgos
//
//  Created by Nicolas Audren on 15/05/2016.
//  Copyright © 2016 Nicosoft. All rights reserved.
//

#include "LinkedListTests.h"
#include "LinkedList.h"

// LinkedList tests
bool testEmpty()
{
    LinkedList<int> list;
    if (!list.isEmpty()) {
        cout << "testEmpty() failed! list.isEmpty() is false" << endl;
        return false;
    }
    
    if (list.getCount() > 0) {
        cout << "testEmpty() failed! list.getCount() is > 0" << endl;
        return false;
    }
    
    if (list.popFront()) {
        cout << "testEmpty() failed! list.popFront() is true" << endl;
        return false;
    }
    
    if (list.popEnd()) {
        cout << "testEmpty() failed! list.popEnd() is true" << endl;
        return false;
    }
    
    return true;
}

bool testAddition()
{
    LinkedList<int> list;
    int value1 = 1;
    list.pushFront(value1);
    if (list.getCount() != 1) {
        cout << "testAddition() failed! list.getCount() is not 1" << endl;
        return false;
    }
    if (!list.first) {
        cout << "testAddition() failed! list.first is nullptr" << endl;
        return false;
    }
    
    if (list.first->value != value1) {
        cout << "testAddition() failed! list.first->value is not " << value1 << endl;
        return false;
        
    }
    
    LinkedList<string> list2;
    string value2 = "toto";
    list2.pushEnd(value2);
    if (list2.getCount() != 1) {
        cout << "testAddition() failed! list2.getCount() is not 1" << endl;
        return false;
    }
    if (!list2.first) {
        cout << "testAddition() failed! list2.first is nullptr" << endl;
        return false;
    }
    
    if (list2.first->value != value2) {
        cout << "testAddition() failed! list2.first->value is not " << value2 << endl;
        return false;
        
    }
    
    return true;
}

bool testDeletion()
{
    LinkedList<string> list;
    string values[4] = {"riri", "fifi", "loulou","picsou"};
    for (string s : values ) {
        list.pushFront(s);
    }
    
    list.popEnd();
    if (list.getCount() != 3) {
        cout << "testAddition() failed! list.getCount() is not 3" << endl;
        return false;
    }
    
    list.pushEnd("donald");
    
    list.popFront();
    if (list.getCount() != 3) {
        cout << "testAddition() failed! list.getCount() is not 3" << endl;
        return false;
    }
    
    if (list.first->value != "loulou") {
        cout << "testAddition() failed! list2.first->value is not loulou" << endl;
        return false;
    }
    
    list.popEnd();
    list.popEnd();
    list.popEnd();
    if (!list.isEmpty()) {
        cout << "testDeletion() failed! list.isEmpty() is false" << endl;
        return false;
    }
    
    return true;
}

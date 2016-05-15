//
//  main.cpp
//  DataStructsAndAlgos
//
//  Created by Nicolas Audren on 14/05/2016.
//  Copyright © 2016 Nicosoft. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "LinkedListTests.h"


int main(int argc, const char * argv[])
{
    bool testOK = testEmpty();
    if (!testOK) {
        return 0;
    }
    
    testOK = testAddition();
    if (!testOK) {
        return 0;
    }
    
    testOK = testDeletion();
    if (!testOK) {
        return 0;
    }
    
    return 0;
}

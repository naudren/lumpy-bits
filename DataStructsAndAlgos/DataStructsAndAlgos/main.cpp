//
//  main.cpp
//  DataStructsAndAlgos
//
//  Created by Nicolas Audren on 14/05/2016.
//  Copyright © 2016 Nicosoft. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#include "ErrorCodes.h"
#include "LinkedListTests.h"
#include "Tree.h"


int main(int argc, const char * argv[])
{
    if (argc > 1) {
        if ( strcmp(argv[1], "-dbll") == 0 )
        {
            if ( !testLinkedList() )
            {
                return LINKED_LIST_TEST_FAILED;
            }
        }
    }
    
    return 0;
}

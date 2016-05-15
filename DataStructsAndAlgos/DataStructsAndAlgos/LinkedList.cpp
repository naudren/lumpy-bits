//
//  LinkedList.cpp
//  DataStructsAndAlgos
//
//  Created by Nicolas Audren on 15/05/2016.
//  Copyright © 2016 Nicosoft. All rights reserved.
//
#include <iostream>
#include <stdio.h>

using namespace std;

// contructor
template<class T>
LinkedList<T>::LinkedList()
: first(nullptr)
{
    
}

// destructor
template<class T>
LinkedList<T>::~LinkedList()
{
#ifdef DEBUG_LINKEDLIST
    cout << "~LinkedList(): " << std::endl;
#endif
    //delete all nodes
    Node * node = first;
    while (node) {
        Node* nodeToDelete = node;
        node = node->next;
#ifdef DEBUG_LINKEDLIST
        cout << "deleting node " << nodeToDelete->value << endl;
#endif
        delete nodeToDelete;
    }
}

// capacity
template<class T>
bool LinkedList<T>::isEmpty() const
{
    return first == nullptr;
}

template<class T>
int LinkedList<T>::getCount() const
{
    int currentCount = 0;
    Node* currentNode = first;
    while (currentNode) {
        currentCount++;
        currentNode = currentNode->next;
    }
    
    return currentCount;
}

// insertion
template <class T>
void LinkedList<T>::pushFront(T value) {
#ifdef DEBUG_LINKEDLIST
    cout << "pushFront(): " << endl;
    printSelf();
#endif
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = first;
#ifdef DEBUG_LINKEDLIST
    cout << "adding " <<  newNode->value << endl;
#endif
    first = newNode;
#ifdef DEBUG_LINKEDLIST
    printSelf();
#endif
}

template <class T>
void LinkedList<T>::pushEnd(T value) {
#ifdef DEBUG_LINKEDLIST
    cout << "pushEnd(): " << endl;
    printSelf();
#endif
    Node* newNode = new Node();
    newNode->value = value;
#ifdef DEBUG_LINKEDLIST
    cout << "adding " <<  newNode->value << endl;
#endif
    if (isEmpty()) {
        first = newNode;
    }
    else
    {
        Node* node = first;
        while (node->next) {
            node = node->next;
        }
        
        node->next = newNode;
    }
    
#ifdef DEBUG_LINKEDLIST
    printSelf();
#endif
}

// deletion
template<class T>
bool LinkedList<T>::popFront()
{
#ifdef DEBUG_LINKEDLIST
    cout << "popFront(): " << endl;
    printSelf();
#endif
    if (isEmpty())
    {
#ifdef DEBUG_LINKEDLIST
        cout << "list is empty, do nothing" << endl;
#endif
        return false;
    }
    Node* nodeToDelete = first;
    first = first->next;
#ifdef DEBUG_LINKEDLIST
    cout << "removing " <<  nodeToDelete->value << endl;
#endif
    delete nodeToDelete;
#ifdef DEBUG_LINKEDLIST
    printSelf();
#endif
    return true;
}

template<class T>
bool LinkedList<T>::popEnd()
{
#ifdef DEBUG_LINKEDLIST
    cout << "popEnd(): ";
    printSelf();
#endif
    if (isEmpty())
    {
#ifdef DEBUG_LINKEDLIST
        cout << "list is empty, do nothing" << endl;
#endif
        return false;
    }
    Node* node = first;
    Node* previousNode = first;
    while (node) {
        if (node->next) {
            previousNode = node;
            node = node->next;
        }
        else
        {
            break;
        }
        
    }
    if (node == first) {
        if (node) {
#ifdef DEBUG_LINKEDLIST
            cout << "removing " <<  node->value << endl;
#endif
            delete node;
        }
        first = nullptr;
    }
    else if ( previousNode && node )
    {
        previousNode->next = nullptr;
#ifdef DEBUG_LINKEDLIST
        cout << "removing " <<  node->value << endl;
#endif
        delete node;
    }
#ifdef DEBUG_LINKEDLIST
    printSelf();
#endif
    
    return true;
}

#ifdef DEBUG_LINKEDLIST
// utilities
template<class T>
void LinkedList<T>::printSelf()
{
    cout << "List: " << endl;
    Node* node = first;
    while (node) {
        cout << node->value;
        node = node->next;
        if (node)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}
#endif

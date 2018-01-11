
/*
 * File:   linked_list.h
 * Author: Simon Powers
 *
 * Last modified 03/03/2017
 * Specification for the LinkedList class.
 */

#pragma once

#include <iostream>
#include <string>

// Node of the list

struct Node {
    // Data stored in this node of the list
    int data;
    // The next node in the list
    Node *next = nullptr;
};

class LinkedList {
private:
    //Pointer to the head node
    Node *head = nullptr;
    //Pointer to the tail node
    Node *tail = nullptr;

public:
    //creates an empty list
    LinkedList();
    //creates a list with an initial value to store
    LinkedList(int value);
    //creates a list by (deep) copying an existing list
    LinkedList(const LinkedList &rhs);
    //destroys (cleans up) the list
    ~LinkedList();
    //adds a value to the head of the list
    void push(int value);
    //removes and returns the value at the head of the list
    //requires: list not empty
    int pop();
    //gets the last element from the list, without removing it
    //requires: list not empty
    int peekTail();
    //adds a value to the end of the list
    void append(int value);
    //appends the deep copies of the nodes of rhs on to the end of this list.
    void appendList(const LinkedList &rhs);
    //inserts a value immediately after the first occurrence of afterValue,
    //if afterValue is not in the list then inserts at the tail.
    void insertAfter(int value, int afterValue);
    //removes all occurrences of value from the list
    void removeAllOccurences(int value);
    //reverses the list
    void reverse();
    //prints the list in order from head to tail
    std::string toString() const;
    //copy assignment operator (performs a deep copy)
    LinkedList& operator=(const LinkedList &other);
    //checks if two lists are equal in state (contain the same values in the same order)
    bool operator==(const LinkedList &other) const;
    //checks if two lists are not equal in state
    bool operator!=(const LinkedList &other) const;
    //pushes a new value onto the head of the list
    LinkedList& operator+(int value);
    //pushes values from an input stream onto the front of the list
    friend std::istream& operator>>(std::istream &in, LinkedList &value);
    //writes the values, in order, to an output stream
    friend std::ostream& operator<<(std::ostream &out, const LinkedList &value);
};

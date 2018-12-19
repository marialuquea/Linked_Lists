/*
 * File:   main.cpp
 * Author: Simon Powers
 *
 * Last modified 02/03/2017.
 * Test driver for the LinkedList class.
 */


#include <string>
#include <iostream>
#include <sstream>
#include "linked_list.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    // Test 1 - basic constructor
    LinkedList *list1 = new LinkedList();
    string str = list1->toString();
    if (str != string(""))
        cerr << "ERROR - test 1 failed (basic constructor)" << endl;
    else
        cout << "Test 1 passed (basic constructor)" << endl;
    delete list1;

    // Test 2 - single value constructor
    list1 = new LinkedList(10);
    str = list1->toString();
    if(str != string("10"))
        cerr << "ERROR - test 2 failed (single value constructor)" << endl;
    else
        cout << "Test 2 passed (single value constructor)" << endl;
    delete list1;

    //Test 3 - push method
    list1 = new LinkedList();
    list1->push(1);
    list1->push(2);
    list1->push(3);
    str = list1->toString();
    if(str != string("3 2 1"))
        cerr << "ERROR - test 3 failed (push method)" << endl;
    else
        cout << "Test 3 passed (push method)" << endl;
    delete list1;

    // Test 4 - append method
    list1 = new LinkedList();
    list1->append(1);
    list1->append(2);
    list1->append(3);
    str = list1->toString();
    if(str != string("1 2 3"))
        cerr << "ERROR - test 4 failed (append method)" << endl;
    else
        cout << "Test 4 passed (append method)" << endl;
    delete list1;

    //Test 5 - insert after method
    list1 = new LinkedList(1);
    int after = 1;
    list1->insertAfter(2,after);
    list1->insertAfter(3,after);
    after = 2;
    list1->insertAfter(4,after);
    str = list1->toString();
    if(str != string("1 3 2 4"))
        cerr << "ERROR - test 5 failed (insert after method)" << endl;
    else
        cout << "Test 5 passed (insert after method)" << endl;
    delete list1;

    //Test 6a - pop method on a list with a single element
    list1 = new LinkedList(1);
    int result = list1->pop();
    str = list1->toString();
    if (str != string("") || result != 1)
        cerr << "ERROR - test 6a failed (pop from a single element list)" << endl;
    else
        cout << "Test 6a passed (pop from a single element list)" << endl;
    delete list1;

     //Test 6b - pop method on a list with three elements
    list1 = new LinkedList(1);
    list1->push(2);
    list1->push(3);
    result = list1->pop();
    str = list1->toString();
    if (str != string("2 1") || result != 3)
        cerr << "ERROR - test 6b failed (pop from a three element list)" << endl;
    else
        cout << "Test 6b passed (pop from a three element list)" << endl;
    delete list1;

    //Test 7 - peek tail method
    list1 = new LinkedList(1);
    list1->append(2);
    list1->append(3);
    list1->append(4);
    list1->append(5);
    result = list1->peekTail();
    str = list1->toString();
    if (str != string("1 2 3 4 5") || result != 5)
        cerr << "ERROR - test 7 failed (peek tail)" << endl;
    else
        cout << "Test 7 passed (peek tail)" << endl;
    delete list1;

    //Test 8a - remove the only element
    list1 = new LinkedList(23);
    list1->removeAllOccurences(23);
    str = list1->toString();
    if (str != string(""))
        cerr << "ERROR - test 8a failed (remove only element" << endl;
    else
        cout << "Test 8a passed (remove only element)" << endl;
    delete list1;

    //Test 8b - try to remove from an empty list
    list1 = new LinkedList();
    list1->removeAllOccurences(23);
    str = list1->toString();
    if (str != string(""))
        cerr << "ERROR - test 8b failed (try to remove from empty list)" << endl;
    else
        cout << "Test 8b passed (try to remove from empty list)" << endl;
    delete list1;


    //Test 8c - remove an element that occurs once
    list1 = new LinkedList();
    list1->append(3);
    list1->append(27);
    list1->append(11);
    list1->append(55);
    list1->append(600);
    list1->removeAllOccurences(11);
    str = list1->toString();
    if (str != string("3 27 55 600"))
        cerr << "ERROR - test 8c failed (remove an element that occurs once)" << endl;
    else
        cout << "Test 8c passed (remove an element that occurs once)" << endl;
    delete list1;

    //Test 8d - remove an element that occurs multiple times
    list1 = new LinkedList();
    list1->append(3);
    list1->append(27);
    list1->append(11);
    list1->append(55);
    list1->append(11);
    list1->append(600);
    list1->append(11);
    list1->removeAllOccurences(11);
    str = list1->toString();
    if (str != string("3 27 55 600"))
        cerr << "ERROR - test 8d failed (remove an element that occurs multiple times)" << endl;
    else
        cout << "Test 8d passed (remove an element that occurs multiple times)" << endl;
    delete list1;

    //Test 9a - reverse a single element list
    list1 = new LinkedList(3);
    list1->reverse();
    str = list1->toString();
    if (str != string("3"))
        cerr << "ERROR - test 9a failed (reverse a single element list)" << endl;
    else
        cout << "Test 9a passed (reverse a single element list)" << endl;
    delete list1;

    //Test 9b - reverse a list with more than one element
    list1 = new LinkedList(5);
    list1->append(4);
    list1->append(3);
    list1->append(2);
    list1->append(1);
    list1->append(0);
    list1->reverse();
    str = list1->toString();
    if (str != string("0 1 2 3 4 5"))
        cerr << "ERROR - test 9b failed (reverse a list with more than one element)" << endl;
    else
        cout << "Test 9b passed (reverse a list with more than one element)" << endl;
    delete list1;

    //Test 10a - append an empty list
    LinkedList *list2 = new LinkedList();
    list1 = new LinkedList(3);
    list1->append(2);
    list1->appendList(*list2);
    str = list1->toString();
    if (str != string("3 2"))
        cerr << "ERROR - test 10a failed (append an empty list)" << endl;
    else
        cout << "Test 10a passed (append an empty list)" << endl;
    delete list1;
    delete list2;

    //Test 10b - append a non-empty list
    list1 = new LinkedList(3);
    list1->append(2);
    list2 = new LinkedList(25);
    list2->append(33);
    list2->append(26);
    list1->appendList(*list2);
    str = list1->toString();
    if (str != string("3 2 25 33 26"))
        cerr << "ERROR - test 10b failed (append a non-empty list)" << endl;
    else
        cout << "Test 10b passed (append a non-empty list)" << endl;

    //Test 10c -- checking the nodes in list 1 are a deep copy
    list2->append(12);
    str = list1->toString();
    if (str != string("3 2 25 33 26"))
        cerr << "ERROR - test 10c failed (checking appended list is a deep copy)" << endl;
    else
        cout << "Test 10c passed (checking appended list is a deep copy)" << endl;
    delete list1;
    delete list2;

    //Test 11a - copy constructor copies nodes
    list1 = new LinkedList(45);
    list1->append(20);
    list1->append(30);
    list2 = new LinkedList(*list1);
    str = list2->toString();
    if (str != string("45 20 30"))
        cerr << "ERROR - test 11a failed (copy constructor copies nodes)" << endl;
    else
        cout << "Test 11a passed (copy constructor copies nodes)" << endl;

    //Test 11b - checking for a deep copy constructor
    list1->append(400);
    str = list2->toString();
    if (str != string("45 20 30"))
        cerr << "ERROR - test 11b failed (copy constructor deep copy check)" << endl;
    else
        cout << "Test 11b passed (copy constructor deep copy check)" << endl;
    delete list1;
    delete list2;

    //Test 12 - assignment operator
    list1 = new LinkedList();
    list1->append(200);
    list1->append(300);
    list1->append(500);
    list2 = new LinkedList();
    list2->append(700);
    list2->append(800);
    list2->append(1000);
    *list1 = *list2;
    list2->append(1200);
    str = list1->toString();
    if (str != string("700 800 1000"))
        cerr << "ERROR - test 12 failed (assignment operator)" << endl;
    else
        cout << "Test 12 passed (assignment operator)" << endl;
    delete list1;
    delete list2;

    //Test 13 - == operator
    list1 = new LinkedList(1);
    list1->append(2);
    list1->append(3);
    list2 = new LinkedList(1);
    list2->append(2);
    list2->append(3);
    if(*list1 == *list2)
        cout << "Test 13 passed (== operator)" << endl;
    else
        cerr << "ERROR - test 13 failed (== operator)" << endl;

    //Test 14 - != operator
    list2->append(4);
    if(*list1 != *list2)
        cout << "Test 14 passed (!= operator)" << endl;
    else
        cerr << "ERROR - test 14 failed (!= operator)" << endl;


    delete list1;
    delete list2;

    //Test 15 - add operator
    list1 = new LinkedList();
    *list1 = *list1 + 10;
    *list1 = *list1 + 4;
    *list1 = *list1 + 11;
    str = list1->toString();
    if (str != string("11 4 10"))
        cerr << "ERROR - test 15 failed (+ operator)" << endl;
    else
        cout << "Test 15 passed (+ operator)" << endl;
    delete list1;

    //Test 16 - output stream operator
    list1 = new LinkedList(10);
    list1->append(11);
    list1->append(12);
    list1->append(13);
    list1->append(14);
    stringstream outstream;
    outstream << *list1;
    if(outstream.str() != string("10 11 12 13 14"))
         cerr << "ERROR - test 16 failed (output stream operator)" << endl;
    else
        cout << "Test 16 passed (output stream operator)" << endl;
    delete list1;

    //Test 17 - input stream operator
    list1 = new LinkedList();
    stringstream instream;
    instream << " 10" << " 11" << " 10" << " 2" << endl;
    instream >> *list1;
    str = list1->toString();
    if (str != string("2 10 11 10"))
        cerr << "ERROR - test 17 failed (input stream operator)" << endl;
    else
        cout << "Test 17 passed (input stream operator)" << endl;
    delete list1;
}

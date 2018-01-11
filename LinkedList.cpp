/*
 * File:   LinkedList.cpp
 * Author: Maria Luque
 * Napier number: 40280156
 *
 * Last modified 02/04/2017
 * Implements the LinkedList class.
 */

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include "linked_list.h"

using namespace std;

//creates an empty list
LinkedList::LinkedList()
{
}

//creates a list with an initial value to store
LinkedList::LinkedList(int value)
{
  head = new Node; //create first node
  head->data = value; //store the value given in it
  tail = head; //both head and tail should point to it
}

//copy constructor (performs a deep copy)
LinkedList::LinkedList(const LinkedList& rhs)
{
  Node* temp = rhs.head;

  //check if there is a list
  while(temp != nullptr)
  {
    //add value to a new node at the end of the list
    append(temp->data);
    temp = temp->next;
  }
}

//destroys (cleans up) the list
LinkedList::~LinkedList()
{
  //Copy head node into temporay node
  Node *temp = head;
  Node *prev;
  //while the linked linst is not finished
  while(temp != nullptr)
  {
    //Copy the value of the temp node into prev and delete it
    prev = temp;
    temp = temp->next;
    delete prev;
  }
  //When the list is empty, set head and tail to nullptr
  head = tail = nullptr;
}

//adds a value to the head of the list
void LinkedList::push(int value)
{
  //If there is no list, create a new node to insert the value
  if(head == nullptr)
  {
    head = new Node;
    head->data = value;
    tail = head;
  }
  else
  {
    //create temporary node to store the given value
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    //Set the new node to be the head of the list
    head = temp;
  }
}

//gets the last element from the list, without removing it
//requires: list not empty
int LinkedList::peekTail()
{
  //if the list is empty
  if(head == nullptr)
  {
    return -1;
  }
  else  //If there are values in a list
  {
    //return the value stored in the tail
    return tail->data;
  }
}

//prints the list in order from head to tail
string LinkedList::toString() const
{
  string str = "";

  if(head == nullptr) //if the list is empty
  {
    return "";
  }
  else //if it's not empty
  {
    Node* temp = head;
    while(temp != nullptr) //while the list hasn't finished
    {
      //Cast value to string and add at the end of the str variable
      str.append(to_string(temp->data));
      temp = temp->next; //read the next value

      //if temp is at the last node
      if(temp != nullptr)
        //add a space so that the numbers are printed with a space between them
        str.append(" ");
    }
  }
  //return the string of numbers
  return str;
}

//removes and returns the value at the head of the list
//requires: list not empty
int LinkedList::pop()
{
  //makae sure that the list is not empty
  assert(head != nullptr);
  Node* temp = head;
  //store the value of the head (start) of the list
  int i = 0;
  i = head->data;
  head = head->next;
  delete temp; //remove the node
  return i; //return the value

}

//adds a value to the end of the list
void LinkedList::append(int value)
{
   //Check if the list is empty
   if (head == nullptr)
   {
     //create a new node to store the value
     Node* temp = new Node;
     temp->data = value;
     head = tail = temp;
   }
   else //if the list is not empty
   {
     //create a new node at the tail and make it point to nullptr
     Node *temp = new Node;
     temp->data = value;
     temp->next = nullptr;
     tail->next = temp;
     tail = temp;
   }
}

//appends the deep copies of the nodes of rhs on to the end of this list
void LinkedList::appendList(const LinkedList& rhs)
{
    Node* temp = rhs.head;
    while(temp != nullptr) //while list is not empty
    {
      append(temp->data); //append each value at the end
      temp = temp->next; //read the next value and repeat process
    }
}

//inserts a value immediately after the first occurrence of afterValue,
//if afterValue is not in the list then inserts at the tail
void LinkedList::insertAfter(int value, int afterValue)
{
  Node* temp = head;
  Node* store_value = new Node;
  Node* after_insert; //pointer to a node

    while (true) //while the list is not empty
    {
      //if the value is found, stop in that node
      if (temp->data == afterValue)
      {
        //point new node to node after the node with the value
        store_value->next = temp->next;
        //the node with the value now points to the new node
        temp->next = store_value;
        //store value given in node
        store_value->data = value;
        return;
      }
      else //If value not found, read next node
      {
        temp = temp->next;
      }
      if (temp == nullptr) //if there is no list
      {
        append(value);
      }
    }
}

//removes all occurrences of value from the list
void LinkedList::removeAllOccurences(int value)
{
  Node *temp;
  Node *prev = nullptr;

  //loop through all the list
  for (temp = head;  temp != nullptr;  temp = temp->next)
  {
      if (temp->data != value) //if the value is not the one
      {
          prev = temp;
          continue; //skip the rest of this iteration of the loop
      }
      if (prev != nullptr) //if there is more than one value
      {
        prev->next = temp->next;
      }
      else //this will only execute if the list only has one value
      {
        head = temp->next;
      }
      delete temp;
  }
}

//reverses the list
void LinkedList::reverse()
{
  Node* tempHead = head;
  Node* restNodes;
  Node* nextNode;

  if (head == nullptr) //is there is no list, do nothing
    return;

  tail = head;

  //separate the first node from the rest
  restNodes = head->next;

  //while there are still nodes after the first one
  while(restNodes != nullptr)
  {
    nextNode = restNodes;
    restNodes = restNodes->next;
    nextNode->next = tempHead;
    tempHead = nextNode;
  }
  //make the node that before was the tail, the head
  head = tempHead;
  tail->next = nullptr; //point last pointer to null
}

//checks if two lists are equal in state (contain the same values in the same order)
bool LinkedList::operator ==(const LinkedList& other) const
{
  //if lhs list in string mode, is the same as the rhs list in string mode
	if (this->toString() == other.toString())
	{
		return true;
	}
	return false;
}

//checks if two lists are not equal in state
bool LinkedList::operator !=(const LinkedList& other) const
{
  //same as before but instead return false
	if (this->toString() == other.toString())
	{
		return false;
	}
	return true;
}

//pushes a new value onto the head of the list
LinkedList& LinkedList::operator +(int value)
{
	push(value); //add (push) value at the head of the list
	return *this; //return whole list
}

//copy assignment operator (performs a deep copy)
LinkedList& LinkedList::operator =(const LinkedList& rhs)
{
	if (head != rhs.head) //if lists are equal
  {
		this->~LinkedList(); //delete lhs list to not have 2

		Node* source = rhs.head;
		Node* next = nullptr;

		while (source != nullptr) //while source list is not empty
    {
      Node* destination = new Node; //new nodes for values in the rhs list

      if (source == rhs.head) //while rhs list is not empty
      {
				head = destination;
			}
      else
      {
				next->next = destination; //point node to the next new node
			}
			tail = destination; //it will always be the tail as we are adding it at the end
			destination->data = source->data; //copy data to new node
			next = destination; //loop through list
			source = source->next;
		}
	}
  return *this;
}

//pushes values from an input stream onto the front of the list
std::istream& operator >> (std::istream &in, LinkedList &value)
{
	char c;
  while(!in.eof()) //while it is not the end of the file
  {
    int x;
	  in.get(c); //read each character one by one
    if (c == '\n') //if there is no value, and it is a new line
    {
      break; //do nothing
    }
    in >> x; //read the value and store it in int x
    value.push(x); //add at the start of the list
  }
  return in;
}

//writes the values, in order, to an output stream
std::ostream& operator<<(std::ostream &out, const LinkedList &value)
{
  //use toString method to print evrything in order
	out << value.toString();
	return out;
}

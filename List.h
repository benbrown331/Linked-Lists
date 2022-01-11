/*
 * Name: Benjamin Brown
 * Date Submitted: 9/5/21
 * Lab Section: 001
 * Assignment Name: Lab 1
 * //node_t *newNode;
    node_t* newNode = (node_t*)malloc(sizeof(node_t));

    while(!feof(input)) {
            newNode=readNodeInfo(input);
            if (newNode!=NULL) {
                add(newNode,head);
                //current=current->next;
            }
    }
    //current->next=NULL;

    return head;
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr) {
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start=nullptr;
  mySize=0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List() {

  //Check to see if list is already empty
  if (empty() == true) {
    cout << "The list is already empty." << endl;
  }
  //Otherwise, empty the list
  else {
  Node<T> *current=start;
  Node<T> *temp;
  //Iterate through list and delete every node
  while (current->next!=nullptr) { //Run loop until the next node is nullptr
    temp=current;
    current=current->next;
    free(temp);
  }
  //free end node
  free(current);
  mySize=0; //reset list size to 0;
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){ //If mySize=0, the list is empty.
  if (mySize==0) {
    return true;
  }
  else {
    return false;
  }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  //Create new node with new value
  Node<T> *newNode=new Node<T>(value);
  //If list is empty, put node at the start
  if (empty()==true) {
    start=newNode;
    mySize++;
  }
  //Otherwise, push previos start node back, and add new node
  else {
  newNode->next=start;
  start=newNode;
  mySize++;
  }
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  //If list is empty, you can insert at start
  if (empty()==true){
    insertStart(value);
  }
  //Otherwise, insert at end of list
  else {
    Node<T> *newNode=new Node<T>(value);
    Node<T> *current=start;
    //iterate though until current is at final node
    while (current->next!=nullptr) {
      current=current->next; //push current ptr back one spot
    }
    current->next=newNode; //place new node where nullptr was
    newNode->next=nullptr;
    mySize++;
  }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  //Check to make sure j is not at beginning or end
  if (j==0 || empty()==true) {
    insertStart(value);
  }
  else if (j>=mySize) {
    insertEnd(value);
  }
  else {
    Node<T> *newNode=new Node<T>(value);
    Node<T> *current=start;
    //iterate until correct position
    int i=0;
    Node<T> *prev=current;
    while (i<j) {
      prev=current;
      current=current->next;
      i++;
    }
    //insert new node at current position
    prev->next=newNode;
    newNode->next=current; //point the new node to the previous spot
    mySize++;
  }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  //check if list is empty or only has 1 element
  if (empty()==true) {
    cout << "Error, list is already empty" << endl;
  }
  /*else if (mySize==1) {
    start=nullptr;
    mySize=0;
  }
  */
  else {
    Node<T> *toDelete=start;
    start=start->next;
    free(toDelete);
    mySize--;
  }
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  //check if list is empty or only has 1 element
  if (empty()==true) {
    cout << "Error, list is already empty" << endl;
  }
  //else if (mySize==1) {
    //start=nullptr;
    //mySize=0;
  //}
  else {
    //iterate to end of list
    Node<T> *current=start;
    Node<T> *prev=current;
    while (current->next!=nullptr) {
      prev=current;
      current=current->next; //push current ptr back one spot
    }
    prev->next=nullptr;
    free(current);
    mySize--;

  }
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  //Ensure j is not at beginnig or end
  if (empty()==true) {
    cout<< "Error, This list is empty" << endl;
  }
  else if (j>mySize) {
    removeEnd();
  }
  else if (j<0) {
    removeStart();
  }
  else {
    Node<T> *current=start;
    Node<T> *prev=current;
    //iterate until correct position
    int i=0;
    while (i<j) {
      prev=current;
      current=current->next;
      i++;
    }
    //delete node at current position
    //point the previous position to the position fter current
    prev->next=current->next;
    mySize--;
    free(current);
  }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  if (empty()==true) {
    cout << "Error, list is empty" << endl;
    return T();
  }
  else {
    return start->value;
  }
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  if (empty()==true) {
    cout << "Error, list is empty" << endl;
    return T();
  }
  else {
    Node<T> *current=start;
    while(current->next!=nullptr) {
      current=current->next;
    }
    return current->value;
  }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  if (empty()==true) {
    cout<<"Error, list is empty" << endl;
    return T();
  }
  else if (j>=mySize) {
    getLast();
  }
  else if (j==0) {
    getFirst();
  }
  else {
    Node<T> *current=start;
    int i=0;
    while (i<j) {
      current=current->next;
      i++;
    }
    return current->value;
  }
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T> *current=start;
  for (int i=0; i<=mySize; i++) {
    if (current->value==key) {
      return i;
    }
    else if (current->next==nullptr) {
      return -1;
    }
    else {
      current=current->next;
    }
  }
}

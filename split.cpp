/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void push_back(Node*& in, Node*& add);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  if (in==nullptr){
    return;
  }
  else if ((in->value)%2==0){
    Node* tmp=in;
    in=in->next;
    tmp->next=nullptr;
    push_back(evens, tmp);
    split(in, odds, evens);
  }
  else if((in->value)%2==1){
    Node* tmp=in;
    in=in->next;
    tmp->next=nullptr;
    push_back(odds, tmp);
    split(in, odds, evens);
  }
}

/* If you needed a helper function, write it here */
void push_back(Node*& in, Node*& add){
  // push a Node pointer to the end of the list recursively, need to preprocess add such that add->next = nullptr
  if (in == nullptr){
    in=add;
  }
  else if(in->next == nullptr){
    in->next = add;
  }
  else{
    push_back(in->next, add);
  }
}
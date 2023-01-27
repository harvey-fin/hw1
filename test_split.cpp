/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node d(0, nullptr);
  Node* odds = nullptr;
  Node* evens = nullptr;
  Node f8(14, nullptr);
  Node f7(11, &f8);
  Node f6(8, &f7);
  Node f5(5, &f6);
  Node f4(4, &f5);
  Node f3(3, &f4);
  Node f2(2, &f3);
  Node f1(1, &f2);

  Node* tmp=&f1;

  while(tmp!=nullptr){
    cout << tmp->value << endl;
    tmp=tmp->next;
  }
  Node* test=&f1;

  split(test, odds, evens);
  if (test==nullptr){
    cout<<"success"<< endl;
  }
  else{
    cout<<"fail"<<endl;
  }
  
  Node* tmp_odds=odds;

  while(tmp_odds!=nullptr){
    cout << tmp_odds->value << " ";
    tmp_odds=tmp_odds->next;
  }
  cout << endl;
  Node* tmp_evens=evens;

  while(tmp_evens!=nullptr){
    cout << tmp_evens->value << " ";
    tmp_evens=tmp_evens->next;
  }


}

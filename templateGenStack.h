#include <iostream>
#include <cstdlib>
#include "RuntimeException.h"
using namespace std;

template <class X>
class GenStack{
private:
  X *myArray;
  int maxSize;
  int top;

public:
  GenStack(); //default constructor
  GenStack(int maxSize); //overload constructor
  ~GenStack(); // destructor

  //functions
  void push(X x); //throw(StackFull); // insert
  X pop() throw (RuntimeException); // remove

  //helper functions
  bool isFull();
  bool isEmpty();
  X peek(); //throw(StackEmpty);
  int size();
  GenStack* moreRoom(int size); // max size of myStack
  //int top(); // variable to keep track of
          // indices representing the top of our myStack

  //char *myArray;
};

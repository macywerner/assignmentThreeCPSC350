#include "templateGenStack.h"

template <class X>
GenStack<X>::GenStack(){ //default constructor
  myArray = new X[1000];
  maxSize = 1000;
  top = -1;
}

//overloaded constructor
template <class X>
GenStack<X>::GenStack(int size){
  myArray = new X[size];
  maxSize = size;
  top = -1;
}

template <class X>
GenStack<X>::~GenStack(){ //destructor
  delete [] myArray;
  myArray = NULL;
  maxSize = 0;
  top = -1;

}

template <class X>
int GenStack<X>::size(){
  return (top + 1); //number of items in the stack
}

/*template <class X>
GenStack<X>* GenStack<X>::moreRoom(GenStack<X>* x, int size){
  int currentSize = size * 2;
  GenStack<X>* newArray = new GenStack<X>(currentSize);
  for (int i = 0; i < currentSize; ++i){
    newArray[i] = x[i];
  }
  return newArray;
}*/

template <class X>
void GenStack<X>::push(X x){
  //check if full before inserting
  if (isFull()){
    cout << "Stack is full." << endl;
    cout << "Allocating now..." << endl;
  }

  myArray[++top] = x; // incrimented top and inserted a value
}

template <class X>
X GenStack<X>::pop() throw (RuntimeException) {
  //check if isEmpty before proceeding to remove
  if (isEmpty()){
    throw RuntimeException("EXCEPTION: Stack is empty.");
  }else{
    return myArray[--top];
  }
}

template <class X>
X GenStack<X>::peek() /*throw(StackEmpty)*/{
  //check if isEmpty before proceeding to remove
  if (isEmpty()){
    //throw StackEmpty("Top of empty stack");
  }
  return myArray[top];
}

template <class X>
bool GenStack<X>::isFull(){ //checks if stack is full
  return (top == maxSize -1);
}

template <class X>
bool GenStack<X>::isEmpty(){ //checks if stack is empty
  return (top == -1);
}

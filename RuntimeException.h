#include <iostream>
using namespace std;

class RuntimeException {
public:
  //StackFull(const string& err) stackFullMsg(err) {};
  RuntimeException();
  RuntimeException(string exception);
  ~RuntimeException();
  /*string getSFMsg(){
    return stackFullMsg;
  }*/
  /*string getSEMsg(){
    return stackEmptyMsg;
  }*/
  /*string getMessage(){
    return errorMessage;
  }*/
  string getSEMsg();

  private:
  //string errorMessage;
  //string stackFullMsg = "Stack is full.";
    string stackEmptyMsg;
};

#include "RuntimeException.h"
using namespace std;

string stackEmptymsg;

// default constructor
RuntimeException::RuntimeException(){
  stackEmptymsg = "";
}

//constructor
RuntimeException::RuntimeException(string exception){
  stackEmptymsg = exception;
}

//destructor
RuntimeException::~RuntimeException(){

}

/*string RuntimeException::getSEMsg(){
  return stackEmptymsg;
}*/

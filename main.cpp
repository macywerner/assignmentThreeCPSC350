
#include "templateGenStack.cpp"
#include <fstream>

int main(int argc, char const *argv[]){

  //command line parameters
  if(argc < 2){
    cout << "invalid command line parameters" << endl;
    return 1;
  }

  string filename = argv[1];
  ifstream inFS; //input file stream

  int z = 0;
  string answer = "";
  int error = 0;

  while (z == 0){
    inFS.open(filename); //open file

    //establish needed variables
    GenStack<char> S; //create stack
    string line = "";
    int lineNum = 0; //variable for the location of character

    if(!inFS.is_open()){ //if file cannot be opened end program
      cout<< "could not open file "<< filename<<endl;
      return 1; //break program
    }

    while(!inFS.eof()){
      lineNum++;
      getline(inFS, line); // read file line by line
      for(int i = 0; i < line.length(); ++i){ //iterate through line for characters
        if (line.at(i) == '(' || line.at(i) == '{' || line.at(i) == '['){ //if opening charaacter
          if(S.isFull()){ // check if stack is full, if full allocate for more room
            /*int size = S.size();
            S = S.moreRoom(S, size);
            S.push(line.at(i));*/
          }else{
            S.push(line.at(i));
          }
        }else if (line.at(i) == ')' || line.at(i) == '}' || line.at(i) == ']'){ //if closing character
          if (S.isEmpty() == true){ //extra character if nothing is in stack or missing opening character to match
            cout << "Line "<< lineNum << ":extra " << line.at(i) << endl;
            error = 1;
          }else if (line.at(i) == ')' && S.peek() == '('){ //if set () pop
            try{
              S.pop();
            }catch (RuntimeException emptyStack){
              //cout << emptyStack.getSEMsg() << endl;
            }
          }else if (line.at(i) == '}' && S.peek() == '{'){ //if set {} pop
            try{
              S.pop();
            }catch (RuntimeException emptyStack){
              //cout << emptyStack.getSEMsg() << endl;
            }
          }else if (line.at(i) == ']' && S.peek() == '['){ //if set [] pop
            try{
              S.pop();
            }catch (RuntimeException emptyStack){
              //cout <<  << endl;
            }
          }
          // if top of stack does not match with closing character report error with location
          else if (S.peek() == '(' && line.at(i) != ')'){
            cout << "Line " << lineNum << ": expected ')' and found " << line.at(i) << endl;
            error = 1;
          }else if (S.peek() == '{' && line.at(i) != '}'){
            cout << "Line " << lineNum << ": expected '}' and found " << line.at(i) << endl;
            error = 1;
          }else if (S.peek() == '[' && line.at(i) != ']'){
            cout << "Line " << lineNum << ": expected ']' and found " << line.at(i) << endl;
            error = 1;
          }
        }
      }
    }

    if (S.isEmpty() == true){ //every symbol is matched
      error = 0;
    }else{ //stack still contains opening character, missing end error
      cout << "Reached end of file: missing }" << endl;
      error = 1;
    }
    if(error == 0){ //while loop, ask for another file to be checked
      cout << "The delimiter syntax is correct." << endl;
      cout << "Would you like to analyze another file? (y or n) ";
      cin >> answer;
    }if(answer == "y"){ //propmt for new file
      cout << "Enter file name: " ;
      cin >> filename;
      z = 0;
    }else{ //exit loop and program
      cout << "Thank you for using this service." << endl;
      S.~GenStack();
      z = 1;
    }
    //error = 0;
  }

}

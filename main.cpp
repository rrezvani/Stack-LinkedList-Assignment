#include "FileProcessor.h"
#include "RPNCalc.h"
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
  FileProcessor *fp = new FileProcessor();
  RPNCalc *rp = new RPNCalc();
  string userInput = "";
  if (strcmp(argv[1], "DNA") == 0) {
    cout << "Please input a filename: ";
    cin >> userInput;
    fp->processFile(userInput);
  }

  else if (strcmp(argv[1], "RPN") == 0) {
    cout << "Please input your calculation: ";
    getline(cin, userInput);
    rp->CalculateString(userInput);
  }

  delete fp;
  delete rp;
  return 0;
}

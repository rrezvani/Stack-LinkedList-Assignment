#ifndef RPN_CALC_H
#define RPN_CALC_H
#include <string>
#include <iostream>
#include "GenStack.h"

using namespace std;

class RPNCalc {
  public:
    RPNCalc();
    ~RPNCalc();
    void CalculateString(string userInput);
    void AssignValues();
    void PerformOperation(int firstNum, int secondNum, char userOperator);
    bool IsOperator(char letter); //all of our custom methods that we use to help implement the RPN calculator
  private:
    GenStack<int> *genStack;
    string operatorList = "+-/*%"; //string with all of the operators
    string stringHolder;
    int stackAdder;
    int firstOperand;
    int secondOperand; //private variables that we use in our class
};

#endif

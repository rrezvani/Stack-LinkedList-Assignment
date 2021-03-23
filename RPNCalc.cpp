#include "RPNCalc.h"

RPNCalc::RPNCalc() {
  genStack = new GenStack<int>(); //initializing our variable
}

RPNCalc::~RPNCalc() {
  delete genStack;
}

void RPNCalc::CalculateString(string userInput) {
  for (int i = 0; i < userInput.length(); ++i) {
    if (userInput[i] == ' ') { //whenever there's a space, 1 of 2 things will happen.
      if (stringHolder == "") { //if stringHolder is empty, it will pass
        continue;
      }
      else { //if stringHolder has some value (meaning it has a number)
        stackAdder = stoi(stringHolder); //convert the string to an int
        genStack->push(stackAdder); //add the number to our stack of ints
        stringHolder = ""; //set stringHolder back equal to ""
      }
    }
    else if (IsOperator(userInput[i])){ // when we come across an operator, the following occurs
      AssignValues();
      PerformOperation(firstOperand, secondOperand, userInput[i]); //use the method above to update first and second operand, before calling PerformOperation
    }
    else {
      stringHolder += userInput[i]; //if it's anything else, meaning it will be a number, it will add it to the empty string
    }
  }
  cout << "Final answer: " << genStack->peek() << endl; //print the last remaining number in our stack, which will be the answer
}

void RPNCalc::AssignValues() { //assigns our variables to the values in the stack
  secondOperand = genStack->pop();
  firstOperand = genStack->pop();
}

void RPNCalc::PerformOperation(int firstNum, int secondNum, char userOperator) { //computer the operation based on the given operator
  int result = 0;
  switch (userOperator) {
    case '+':
      result = firstOperand + secondOperand; //adds
      break;

    case '-':
      result = firstOperand - secondOperand; //subtracts
      break;

    case '*':
      result = firstOperand * secondOperand; //multiplies
      break;

    case '/':
      result = firstOperand / secondOperand; //divides
      break;

    case '%':
      result = firstOperand % secondOperand; //modulo
      break;

    default:
      throw runtime_error("Not an operator!");
      break;
  }
  genStack->push(result); //pushing the result back into our stack
}

bool RPNCalc::IsOperator(char letter) { //method that returns true if the value is an operator
  if (operatorList.find(letter) < operatorList.length()) { //if the letter exists in operatorList string defined in the header file, it will return true
    return true;
  }
  return false;
}

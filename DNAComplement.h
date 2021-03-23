#ifndef DNA_COMPLEMENT_H //dna complement class
#define DNA_COMPLEMENT_H

#include <iostream>
#include <string>
#include "GenStack.h"

using namespace std;

class DNAComplement {
  public:
    DNAComplement(); //constructor
    ~DNAComplement(); //deconstructor
    string FindComplement(string dnaString);
    string FindReverseComplement(string stringToAdd);
  private:
    GenStack<char> *gs; //making a stack of chars
};

#endif

#include "DNAComplement.h"

DNAComplement::DNAComplement() {
  gs = new GenStack<char>(); //initalizing our variable
}

DNAComplement::~DNAComplement() {
  delete gs;
}

string DNAComplement::FindComplement(string dnaString) { //method to find the corresponding nucleotide given a string
  string complementString = "";
  for (int i = 0; i < dnaString.length(); ++i) {
    if (toupper(dnaString[i]) == 'A') { //if A, then T
      complementString += 'T';
    }
    else if (toupper(dnaString[i]) == 'T') { //if T, then A
      complementString += 'A';
    }
    else if (toupper(dnaString[i]) == 'C') { //if C, then G
      complementString += 'G';
    }
    else if (toupper(dnaString[i]) == 'G') { //if G, then C
      complementString += 'C';
    }
    else {
      throw runtime_error ("Make sure your dna string has the 4 acceptable options!");
    }
  }
  return complementString; //return the new and improved string
}

string DNAComplement::FindReverseComplement(string stringToAdd) {
  string reverseComplement = "";
  for (int i = 0; i < stringToAdd.length(); ++i) {
    gs->push(stringToAdd[i]); //push all the letters to the stack
  }
  while (!gs->isEmpty()) {
    reverseComplement += gs->pop(); //pop them all back into a string, but doing so reverses the entire sequence
  }
  return FindComplement(reverseComplement); //use our already written function to compute the complement of our new reveresed string
}

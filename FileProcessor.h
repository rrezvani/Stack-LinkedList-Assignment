#ifndef FILE_PROCESSOR_H //header guard
#define FILE_PROCESSOR_H

#include "DNAComplement.h"
#include <fstream> //including a file stream
#include <iostream>
#include <string>

using namespace std;

class FileProcessor
{
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string inputFile); //defining our constructor, destructor, and our 1 function

  private:
    ifstream inFS;
    ofstream outFS; //creating an input file stream and output file stream variables
    string fileSentence; //string that we use in the function
    DNAComplement *dna; // instance of the DNA class
};

#endif

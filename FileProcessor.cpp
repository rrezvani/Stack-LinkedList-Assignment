#include "FileProcessor.h"

FileProcessor::FileProcessor() {
  dna = new DNAComplement(); //initalizing our variable
}

FileProcessor::~FileProcessor() {
  delete dna;
}

void FileProcessor::processFile(string inputFile) {
  inFS.open(inputFile); //open the file we were given
  outFS.open("dnaoutput.txt"); // since we're writing to a given file, we can always open this one

  getline(inFS, fileSentence); //read in the first line
  while (!inFS.fail()) { //run until the last line
    outFS << "Complement: " << dna->FindComplement(fileSentence) << endl; //print complement
    outFS << "Reverse Complement: " << dna->FindReverseComplement(fileSentence) << endl << endl; //print reverse complement
    getline(inFS, fileSentence); //read next line
  }

  inFS.close();
  outFS.close(); //close both streams
}

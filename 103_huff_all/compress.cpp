#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>

#include "node.h"
#include "readFreq.h"

using namespace std;

void writeHeader(BitFileWriter * bfw, const std::map<unsigned, BitString> & theMap) {
  for (int i = 0; i < 257; i++) {
    std::map<unsigned, BitString>::const_iterator it = theMap.find(i);
    if (it != theMap.end()) {
      bfw->writeByte(it->second.size());
      bfw->writeBitString(it->second);
    }
    else {
      bfw->writeByte(0);
    }
  }
}

void writeCompressedOutput(const char * inFile,
                           const char * outFile,
                           const std::map<unsigned, BitString> & theMap) {
  BitFileWriter bfw(outFile);
  writeHeader(&bfw, theMap);

  //WRITE YOUR CODE HERE!
  //open the input file for reading
  ifstream input;
  input.open(inFile);
  char c;
  //You need to read the input file, lookup the characters in the map,
  //and write the proper bit string with the BitFileWriter
  typename map<unsigned, BitString>::const_iterator it;
  while (input.get(c)) {
    it = theMap.find((unsigned char)c);
    assert(it != theMap.end());
    bfw.writeBitString(it->second);
  }
  //dont forget to lookup 256 for the EOF marker, and write it out.

  //BitFileWriter will close the output file in its destructor

  //but you probably need to close your input file.

  it = theMap.find(256);
  assert(it != theMap.end());
  bfw.writeBitString(it->second);
}

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: compress input output\n");
    return EXIT_FAILURE;
  }
  //WRITE YOUR CODE HERE
  //Implement main
  //hint 1: most of the work is already done.
  //hint 2: you can look at the main from the previous tester for 90% of this
  const char *inFile = argv[1], *outFile = argv[2];
  uint64_t * counts = readFrequencies(inFile);
  Node * tree = buildTree(counts);
  delete[] counts;
  BitString bs;
  std::map<unsigned, BitString> theMap;
  tree->buildMap(bs, theMap);
  delete tree;
  writeCompressedOutput(inFile, outFile, theMap);

  return EXIT_SUCCESS;
}

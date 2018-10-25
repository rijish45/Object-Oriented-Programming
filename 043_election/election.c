/*
Rijish Ganguly
ECE 551
Assignment 43
*/

#include "election.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "string.h"
//include any other headers you need here...

void printError();  //function prototype

state_t parseLine(const char * line) {
  //STEP 1: write me

  state_t state;  //do not assign to char[]
  state.electoralVotes = 0;
  state.population = 0;

  //Consider null input
  if (line == NULL) {
    fprintf(stderr, "Error. NULL input was passed to the function. \n");
    exit(EXIT_FAILURE);
  }

  int i = 0;
  //int j = 0; //don't need to keep track of a second pointer

  if (line[i] == ':' || line[i] == '\0' || (!isalpha(line[i]))) {
    printError();
  }

  while (line[i] != ':') {
    if (i >= MAX_STATE_NAME_LENGTH - 1) {  //array indexing cannot exceed 63
      printError();
    }

    else if (line[i] == '\0') {  //should not encounter a \0 while storing the name
      printError();
    }

    else {
      state.name[i] = line[i];
      i++;
    }
  }

  state.name[i] = '\0';  //End the name string with a null terminator
  i++;                   //calibrate to get population now

  while (line[i] != ':') {
    if (line[i] == '\0' || line[i] - '0' > 9 || line[i] - '0' < 0 ||
        isalpha(line[i])) {  //check the digits and make sure that they are between 0 and 9
      printError();
    }

    else {
      state.population =
          state.population * 10 + (unsigned)(line[i] - '0');  //character arithmetic '0' -> 48
      i++;
    }
  }

  i++;  //calibrate to get electoral votes now

  while (line[i] != '\0') {
    if (isalpha(line[i]) || line[i] - '0' > 9 ||
        line[i] - '0' < 0) {  //Check the characters in the string, should be between 0 and 9
      printError();
    }
    else {
      state.electoralVotes = state.electoralVotes * 10 + (unsigned)(line[i] - '0');
      i++;
    }
  }

  return state;
}

//Error function makes sense due to repeated calls to it
void printError() {
  fprintf(stderr, "Incorrect string format. Check your input file.\n");
  exit(EXIT_FAILURE);
}

unsigned int countElectoralVotes(state_t * stateData, uint64_t * voteCounts, size_t nStates) {
  //STEP 2: write me
  unsigned int electVotes = 0;
  if (nStates < 51) {
    fprintf(stderr, "Warning. You are supposed to have 51 states in total.\n");
    // exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < nStates; i++) {
    float compare = (stateData[i].population * 0.5);
    /*  printf("%s , %d , %d, %d \n ",
           stateData[i].name,
           stateData[i].electoralVotes,
           (int)stateData[i].population,
           (int)voteCounts[i]);  */
    if (voteCounts[i] < 1) {
      fprintf(stderr, "Incorrect file format for voteCount.\n");
      exit(EXIT_FAILURE);  //for the case "statename: " with no votecount
    }
    if (voteCounts[i] > stateData[i].population) {  //same error checking case as before
      fprintf(stderr,
              "The number of votes cannot exceed total popualtion of the state. Wrong input. \n");
      exit(EXIT_FAILURE);
    }
    if ((float)voteCounts[i] > compare) {
      electVotes += stateData[i].electoralVotes;  //update electVotes
    }
  }

  return electVotes;
}

void printRecounts(state_t * stateData, uint64_t * voteCounts, size_t nStates) {
  //STEP 3: write me

  if (nStates <
      51) {  //To test smaller inputs, comment this out. Shouldn't have had the exit(EXIT_FAILURE). As that messed up the pre-grader
    fprintf(stderr,
            "Warning. You are supposed to have 51 states in total. Ignore this if you are testing "
            "program with small input. \n");
    // exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < nStates; i++) {
    float voteCountPerc = voteCounts[i] / (float)stateData[i].population;
    //printf("%.2f \n", voteCountPerc);
    if (voteCounts[i] < 1) {
      fprintf(stderr, "Incorrect file format for voteCount.\n");
      exit(EXIT_FAILURE);  //for the case "statename: " with no votecount
    }

    if (voteCounts[i] == 0) {
      fprintf(stderr, "Warning. Candidate received 0 votes from a state");
      exit(EXIT_FAILURE);  //This might be possible but doesn't seem practical in real life
    }

    else if (voteCounts[i] > stateData[i].population) {
      fprintf(stderr,
              "The number of votes cannot exceed total popualtion of the state. Wrong input. \n");
      exit(EXIT_FAILURE);  //Number of votes cannot exceed the population.
    }

    else {  //Had to be careful about the precision
      if (voteCountPerc >= 0.4950 && voteCountPerc <= 0.5050) {
        printf("%s requires a recount (Candidate A has %.2f%% of the vote)\n",
               stateData[i].name,
               voteCountPerc * 100);
      }
    }
  }
}

void printLargestWin(state_t * stateData, uint64_t * voteCounts, size_t nStates) {
  //STEP 4: write me

  float maxPercent = 0;
  char name[64] = "";

  if (nStates <
      51) {  //To test smaller inputs, comment this out. Shouldn't have had the exit(EXIT_FAILURE). As that messed up the pre-grader
    fprintf(stderr,
            "Warning. You are supposed to have 51 states in total. Ignore this if you are testing "
            "program with small input. \n");
    // exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < nStates; i++) {
    if (voteCounts[i] == 0) {  //same check as before
      fprintf(stderr, "Warning. Candidate received 0 votes from a state.\n");
      exit(EXIT_FAILURE);
    }

    if (voteCounts[i] < 1) {
      fprintf(stderr, "Incorrect file format for voteCount. \n");
      exit(EXIT_FAILURE);  //for the case "statename: " with no votecount
    }

    else if (voteCounts[i] > stateData[i].population) {
      fprintf(stderr,
              "The number of votes cannot exceed total popualtion of the state. Wrong input. \n");
      exit(EXIT_FAILURE);
    }
    else {  //store max percent in a variable by repated comparisons
      float voteCountPerc = voteCounts[i] / (float)stateData[i].population;
      if (voteCountPerc > maxPercent) {
        maxPercent = voteCountPerc;       //update maxpercent if condition is true
        strcpy(name, stateData[i].name);  //cannot assign to name, hence needed to copy
      }
    }
  }

  printf("Candidate A won %s with %.2f%% of the vote \n", name, maxPercent * 100);
}

//Text.h
//header file containing text related functions

//include WordList for WordNode type
#include "WordList.h"

//find the required buffer size, take the input file as argument
long bufferSize(FILE *inFile);

/*convert text to lower case and remove symbols (apart from apostrophes) with use
of ASCII values, take the buffer and input file as arguments*/
void formatText(char *buffer, FILE *inFile);

/*separate characters into words and call list making functions, take the buffer,
input file, list and sorted boolean as arguments*/
void wordFinder(char *buffer, FILE *inFile, WordList *wordList, bool sorted);

//check amount of parameters, take number of and array of parameters as arguments
void checkParameters(int numParameters, char **parameters);

//check parameters and decide if sorted list or not, take array of parameters as argument
bool isSorted(char **parameters);

//main.c
//main code file containing main function

//include stdio for fopen(), fread() and fclose()
#include <stdio.h>
//include stdlib for free()
#include <stdlib.h>
//include stdbool for `isSorted` boolean
#include <stdbool.h>
//include time for time()
#include <time.h>
//include Text for all function prototypes
#include "Text.h"

int main (int argc, char **argv)
{
	//get time since Epoch when first running the program
	time_t startTime = time(NULL);
	//check amount of parameters
	checkParameters(argc, argv);
	//open input file with the use of parameter
	FILE *inFile = fopen(argv[1], "r");
	/*declare char array `buffer`, allocate enough memory
	and set last character to string terminator*/
	char *buffer = (char*)malloc(bufferSize(inFile) + 1);
	buffer[bufferSize(inFile)] = '\0';
	//read the input file into the buffer
	fread(buffer, 1, bufferSize(inFile), inFile);
	//convert text to lower case and remove symbols (apart from apostrophes)
	formatText(buffer, inFile);
	//create instance of WordList
	WordList myList;
	//initialise the list to empty
	InitialiseList(&myList);
	//separate characters into words and call list making functions
  wordFinder(buffer, inFile, &myList, isSorted(argv));
	//print the list
	PrintList(&myList);
	//close input file
	fclose(inFile);
	//free memory used by the buffer
	free(buffer);
	//get time since Epoch once program is done running
	time_t endTime = time(NULL);
	//print the difference between endTime and startTime for total time taken
	printf("Time taken: %ld seconds\n\n", endTime - startTime);
	return (0);
}

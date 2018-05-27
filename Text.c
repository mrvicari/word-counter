//Text.c
//code file containing definition of text related functions

//include stdio for printf(), fseek() and ftell()
#include <stdio.h>
//include stdlib for exit()
#include <stdlib.h>
//include ctype for isalpha()
#include <ctype.h>
//include string for strlen()
#include <string.h>
//include stdbool for `sorted` boolean
#include <stdbool.h>
//include Text for function prototypes, WordList and WordNode
#include "Text.h"

//find the required buffer size, take the input file as argument
long bufferSize(FILE *inFile)
{
	//find the end of the file
	fseek(inFile, 0, SEEK_END);
	//assign the length to variable `size`
	long size = ftell(inFile);
	//return to beginning of the file
	fseek(inFile, 0, SEEK_SET);
	//return `size` value
	return size;
}

/*convert text to lower case and remove symbols (apart from apostrophes) with use
of ASCII values, take the buffer and input file as arguments*/
void formatText(char *buffer, FILE *inFile)
{
	//variable to loop through the buffer
	int bufferIndex;
	//for loop over the buffer
	for (bufferIndex = 0; bufferIndex < bufferSize(inFile); ++bufferIndex)
	{
		//if character is upper case letter. A = 65 and Z = 90
		if (*(buffer + bufferIndex) > 64 && *(buffer + bufferIndex) < 91)
		{
			//make it lower case.
			*(buffer + bufferIndex) = *(buffer + bufferIndex) + 32;
		}
		//if character is not a letter nor an apostrophe. '''(apostrophe) = 39
		if (!isalpha(*(buffer + bufferIndex)) && *(buffer + bufferIndex) != 39)
		{
			//make it blankspace. ' ' = 32
			*(buffer + bufferIndex) = 32;
		}
		//if character is an apostrophe and next one is not a letter. '''(apostrophe) = 39
		if (*(buffer + bufferIndex) == 39 && !isalpha(*(buffer + (bufferIndex + 1))) )
		{
			//make it blankspace. ' ' = 32
			*(buffer + bufferIndex) = 32;
		}
	}
}

/*separate characters into words and call list making functions, take the buffer,
input file, list and sorted boolean as arguments*/
void wordFinder(char *buffer, FILE *inFile, WordList *wordList, bool sorted)
{
	//variables to loop through the buffer and current word being written
  int bufferIndex, wordIndex = 0;
	//array to hold current word
  char currentWord[50];
	//for loop over the buffer
  for (bufferIndex = 0; bufferIndex < bufferSize(inFile); ++bufferIndex)
	{
		//if first character or character right after a space. ' ' = 32
		if (bufferIndex == 0 || *(buffer + (bufferIndex - 1)) == 32)
		{
			//loop while current character is a letter or apostrophe. a = 97 and z 122. '''(apostrophe) = 39
			while (*(buffer + bufferIndex) > 96 && *(buffer + bufferIndex) < 123 || *(buffer + bufferIndex) == 39)
			{
				//if the first character of a word is an apostrophe. '''(apostrophe) = 39
				if (wordIndex == 0 && *(buffer + bufferIndex) == 39)
				{
					//skip it
					bufferIndex++;
				}
				//set the first character of current word to be the current character in the buffer
				currentWord[wordIndex] = *(buffer + bufferIndex);
				//increment the index of the current word
				wordIndex++;
				//increment the buffer looping index
				bufferIndex++;
			}
		}
		//when while loop breaks place string terminator in current word
		currentWord[wordIndex] = '\0';
		//if current word is not empty
		if (strlen(currentWord))
    {
			//look for current word in list
			//if not found
      if (!FindByKey(wordList, currentWord))
      {
				//if sorted boolean is true
				if (sorted)
				{
					//add new filled node with current word and count 1, in correct position
	        AddNodeSorted(wordList, CreateFilledNode(currentWord, 1));
				}
				//if sorted boolean is false
				else
				{
					//add new filled node with current word and count 1
	        AddNode(wordList, CreateFilledNode(currentWord, 1));
				}
      }
			//if current word is found in the list
      else
      {
				//increment the count inside the word node
        incrementCount(FindByKey(wordList, currentWord));
      }
    }
		//set the current word index back to zero for next word
		wordIndex = 0;
	}
}

//check amount of parameters, take number of and array of parameters as arguments
void checkParameters(int numParameters, char **parameters)
{
	//if there are less than 2 parameters
	if (numParameters < 2)
	{
		//print not enough parameters error
		printf("\nError: not enough parameters\n\n");
		exit(-1);
	}
	//if there are more than 3 parameters
	else if (numParameters > 3)
	{
		//print too many parameters error
		printf("\nError: too many parameters\n\n");
		exit(-1);
	}
	//if opening the file returns NULL
	if (!fopen(parameters[1], "r"))
	{
		//print file not found error
		printf("\nError: file not found\n\n");
		exit(-1);
	}
}

//check parameters and decide if sorted list or not, take array of parameters as argument
bool isSorted(char **parameters)
{
	//declare boolean sorted
	bool sorted;
	//if there is a third parameter and its first letter is 's'
	if (parameters[2] && parameters[2][0] == 's')
	{
		//sorted boolean is true
		sorted = true;
		//return boolean to the function
		return sorted;
	}
	//if the first letter is not 's' or there is not a third parameter
	else
	{
		//set sorted to false
		sorted = false;
		//return boolean to the function
		return sorted;
	}
}

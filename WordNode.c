//WordNode.c
//code file containing definition of node functions

//include stdio for printf()
#include <stdio.h>
//include stdlib for malloc()
#include <stdlib.h>
//include string for strdup()
#include <string.h>
//include WordNode for function prototypes
#include "WordNode.h"

//create a new node with information, take the word and number as arguments
WordNode *CreateFilledNode(char *wordIn, int countIn)
{
	//allocate memory for the new node
	WordNode *newNode = (WordNode*)malloc(sizeof(WordNode));
	//copy the arguments into the node
	newNode->word = strdup(wordIn);
	newNode->count = countIn;
	//pointer to the next node is NULL
	newNode->nextWord = NULL;
	//return the new node
	return newNode;
}

//print a node, take a node as argument
void PrintNode(WordNode *wordNode)
{
	//print the information held in the node
	printf("%15s: %5d\n", wordNode->word, wordNode->count);
}

//increment word count in node, take node as argument
void incrementCount(WordNode *wordNode)
{
	//increase the value of count within the node by 1
  wordNode->count += 1;
}

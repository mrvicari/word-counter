//WordList.c
//code file containing definition of list functions

//include stdio for printf()
#include <stdio.h>
//include string for strcmp()
#include <string.h>
//include WordList for function prototypes and WordNode
#include "WordList.h"

//initialise the list to empty, take list as argument
void InitialiseList(WordList *wordList)
{
  //set the pointer to the first node to NULL
  wordList->topNode = NULL;
}

//print the list, take list as argument
void PrintList(WordList *wordList)
{
  //a node to loop through the list
  WordNode *walkNode = wordList->topNode;
  //print visual break
  printf("\n");
  //loop through the list until pointer is NULL
  for ( ; walkNode != NULL; walkNode = walkNode->nextWord)
  {
    //print every node
    PrintNode(walkNode);
  }
  //print visual break
  printf("\n");
}

//add  new node to beginning, take list and node as arguments
void AddNode (WordList *wordList, WordNode *wordNode)
{
  //set new node pointer to previous top node
  wordNode->nextWord = wordList->topNode;
  //set top node pointer to the new node
  wordList->topNode = wordNode;
}

//find node with key word, take list and key word as arguments
WordNode *FindByKey(WordList *wordList, char *keyWord)
{
  //pointer to hold key word
  WordNode *keyNode = wordList->topNode;
  //while the current node is not NULL
  while (keyNode != NULL)
  {
    //compare key word with word in node
    if (strcmp(keyNode->word, keyWord) == 0)
    {
      //if found return that node
      return keyNode;
    }
  //if not found yet, move to the next node
  keyNode = keyNode->nextWord;
  }
//if while loop breaks, return NULL node
return keyNode;
}

//add new node in correct alphabetical position, tkae list and node as arguments
void AddNodeSorted(WordList *wordList, WordNode *wordNode)
{
  //if the list is empty
  if (wordList->topNode == NULL)
  {
    //set the pointer to the first node to NULL
    wordNode->nextWord = NULL;
    //set the list pointer to point to the new node
    wordList->topNode = wordNode;
  }
  //if the new node is to be added at the beginning of the list
  else if (strcmp(wordNode->word, wordList->topNode->word) < 0)
  {
    //set the new node's pointer to the current first node
    wordNode->nextWord = wordList->topNode;
    //set the list's top node pointer to the new node
    wordList->topNode = wordNode;
  }
  //if the new node is to be added somewhere in the middle of the list
  else
  {
    //a node to loop through the list, start at the top
    WordNode *searchNode = wordList->topNode;
    //while not at the last node
    while (searchNode->nextWord != NULL)
    {
      //if new node belongs before the next node
      if (strcmp(wordNode->word, searchNode->nextWord->word) < 0)
      {
        //set the new node's pointer to the next node
        wordNode->nextWord = searchNode->nextWord;
        //set the previous node's pointer to the new node
        searchNode->nextWord = wordNode;
        //return to escape the next instructions, as the position was found
        return;
      }
    //move on to the next node
    searchNode = searchNode->nextWord;
    }
  //if the new node belongs at the end of the list
  //set the new node's pointer to NULL
  wordNode->nextWord = NULL;
  //add the new node at the end
  searchNode->nextWord = wordNode;
  }
}

//WordList.h
//header file containing list struct and list related function prototypes

//include WordNode for the node struct
#include "WordNode.h"

//list struct
struct word_list
{
  //pointer to the first node
  WordNode *topNode;
};
//typedef to rename the struct
typedef struct word_list WordList;

//initialise the list to empty, take list as argument
void InitialiseList(WordList *wordList);

//print the list, take list as argument
void PrintList(WordList *wordList);

//add new node to beginning, take list and node as arguments
void AddNode (WordList *wordList, WordNode *wordNode);

//find node with key word, take list and key word as arguments
WordNode *FindByKey(WordList *wordList, char *keyWord);

//add new node in correct alphabetical position, tkae list and node as arguments
void AddNodeSorted(WordList *wordList, WordNode *wordNode);

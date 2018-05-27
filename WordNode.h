//WordNode.h
//Header file containing node struct and node related function prototypes

//node struct
struct word_struct
{
	//word being stored
	char *word;
	//number of times the word occurred
	int count;
	//pointer to next node
	struct word_struct *nextWord;
};
//typedef to rename the struct
typedef struct word_struct WordNode;

//create a new node with information, take the word and number as arguments
WordNode *CreateFilledNode(char *wordIn, int countIn);

//print a node, take a node as argument
void PrintNode(WordNode *wordNode);

//increment word count in node, take node as argument
void incrementCount(WordNode *wordNode);

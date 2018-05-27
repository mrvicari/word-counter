WordCount:	main.o	Text.o	WordNode.o	WordList.o
	gcc -o WordCount main.o Text.o WordNode.o WordList.o

main.o:	main.c	WordNode.h	WordList.h
	gcc -c -o main.o main.c

Text.o:	Text.c Text.h WordList.h WordNode.h
	gcc -c -o Text.o Text.c

WordNode.o:	WordNode.c	WordNode.h
	gcc -c -o WordNode.o WordNode.c

WordList.o:	WordList.c	WordList.h	WordNode.h
	gcc -c -o WordList.o WordList.c

clean:
	rm WordCount *.o *~

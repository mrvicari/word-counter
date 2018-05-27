#timetest.sh
#shell script to test time taken by program on set files

#make the executable of the program in case not done already
make

echo ""

echo "*Testing WordCount*"

echo ""

echo "Unsorted Linked List:"
time ./WordCount $1 > /dev/null

echo ""

echo "Sorted Linked List:"
time ./WordCount $1 s > /dev/null

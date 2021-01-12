# Homework 6 Stack & Queue

Write a C program that reads a line from data.txt and creates a singly linked list queue from it.
This C program changes that queue order by **reversing the order of the odd integers** while leaving the even integers in place.  
Run this program for each line of the data.txt file and print out the results.  
The first line of the data.txt file contains the sample count.

Use Singly Linked List, not Array! Solution is based on stack and queue combination.  
Compile your code and include your executable file into your submission. Also include a screenshot of the result screen.

For example given this queue:  
14 13 17 8 4 10 11 4 15 18 19  	//queue
   1  2         3    4     5  	//order of the odd integers

program would change it to:  
14 19 15 8 4 10 11 4 17 18 13  	//queue
   5  4         3    2     1  	//order of the odd integers
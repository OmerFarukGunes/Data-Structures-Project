# Homework 4 Hashing

Write a single program in C. Create a struct array and put every information, that data.txt file consist, into that struct array.

Create a hash table. Table size depends on you however, use as minimum size as possible. Implement **5 different hash functions** (please be creative) and measure the performance of each hash function and output the report to the screen. If you are going to measure the effect of table size, please run 5 hash functions for every table size you tried.

Every step or instruction must be counted, especially the linear probing like collusion resolution parts. Don't use time as a measurement but use complexity analysis or instructions count as a performance measurement technique. Create your formula for the performance report. Include table size in performance measurement.

At the end of your report please show and indicate the **most effective** hash function and/or table size.
Put a single screenshot of outputs and update this README with outputs also.

Please use my main.c file. Do not create a new c file. We only work with C language/files don't use C++/CPP files.
Your outputs must be meaningful. Please use complete sentences.

## Output:

Paste terminal output below:

               
         Collision Values Table For Every Hash Table and Hashing Function

      Hash Table Size:   XS   S    M     L     XL  Performance(sigma(average percentage))


Hashing Methods

Mod Hashing:             415 1884 10915 12364 5402          2200
djb2 Hashing:            287 962  2260  532   294           422
Lose Lose Hanging:       273 940  4201  605   378           566
Knuths Method Hasging:   276 458  3525  247   227           424
Digit Folding Hashing:   225 1247 3558  652   996           580

CONCLUSION: as you can see; Mod Hashing has the worst performance of all.
For minimum size hash table, Digggit Folding hashing has the lowest collision.
when Hash table size and our array size is same, djb2 Method has the best performance.
On the other hand, in hash tables of different sizes knuths string hashing method shows the best performance
The most effective hashing model is djb2 model.
But don't forget we use it with string key, so using integer keys may not be as good as.
The knuth model is good for hashing with integer
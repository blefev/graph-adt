# Graphs

## Details
For this assignment you will be developing a C++ program which implements a
graph data structure. The backing data structure for your graph should be an
_adjacency matrix_. As a method of testing your program will read in a file called
`cmd.txt` which contains commands which tells your program what it should do. 
The name of the file will be given to your program as a command line argument. 
A description of that file has been provided below. The program will also read 
in another file called `edges.txt` which describes the graph that is to be built 
by your program. The file is described below 

This repo contains the following directories:
* `src` - Contains the source code for the assignment and the files you will need
complete. Any modifications you make to complete your assignment should be made
inside this directory.
* `tests` - This directory contains the code that is used to test your program.
You should not modify any code inside of this directory as it could give you
incorrect results. The code in this directory can be compiled and executed when
you beleive your assignment is complete.

## Files
Inside of the `src` directory you will find the following files
* `main.cpp` - This file is the driver of your program. It creates an instance of
your class and then performs various operations that your class implements. It
first reads `edges.txt` and creates the graph. It then moves ahead and 
reads information from `cmd.txt` which instructions the program on what actions
to take. This file has already been completed for you and should not be modified.
* `graph.h` - This file defines and implements the `GRAPH` class. You are 
responsible for implementing all functions of this class.
* `graph.cpp` - This file implements the class interface that is defined in `graph.h`
* `makefile` - This is the file that can be used to build your program. This file
has already been completed and should not be modified.
* `cmd.txt` - This file is a sample cmd file that can be used to test your program's
functionality. You may use it as is or add or change values in order to test
different edge cases.
* `edges.txt` - This is a file which represents edges in a graph. This file currently
has an example graph and may be modified to generate different test cases.
* `pretty_print.h` and `pretty_print.cpp` - These two files define and implement some
functions that help print an ascii representation of a minnimum spanning tree. These
are already completed for you. They are only used by `main.cpp` 

## Your Task
You are to look at the class defined in `graph.h` and create the corresponding
implementation in `graph.cpp`. You may not change any of the existing declarations
but you may add more functions as you deem necesarry.

In short, the following files are the only ones that you should modify for this
assignment:
* `graph.h` - You may only add to this file, not modify existing definitions!
* `graph.cpp`

No other file should be modified!

## cmd File Format
The cmd file for this assignment will consist of one to three columns of numbers. 
The first column indications the function that should be called, the second column
indications the operand that that function may take, and the third parameter 
represents an optional second parameter. The command to function mapping is defined 
below
```
1    bfs
2    dfs
3    dijkstra
4    primm
```

The path to this file will be provided on the cmd line. The name of the file should 
not be hardcoded into your program. Below is an example cmd file 
```
1 2
2 2
3 2 1
4 4
```

## edges File Format
`edges.txt` will have the following format
* line 1: 0 or 1. If 0 is present then the following graph will be undirected.
If 1 is present then the graph is directed
* line 2: The number of nodes in the graph
* rest of file: each line contains a tuple of \<src, dst, weight\>  

A sample file may look like
```
1
7
1 2 2
1 4 1
2 4 3
2 5 10
3 1 4
3 6 5
4 3 2
4 5 2
4 6 8
4 7 4
5 7 6
7 6 1
```

## Interface
Below is the prototype for the graph class you are to implement. This is found
in `graph.h`. Remember you cannot change any existing definitions but you may
add additional functions/variables as necesarry.

```C++
class GRAPH{
public:
    // Constructor to use when we have an initial number of nodes & edges
    GRAPH(int nodes);
    // Constructor for stateing if a a graph is directed or not
    GRAPH(bool is_directed, int nodes);
    // Set the edge going from src to dst
    void set_edge(int src, int dst, int w);
    // Print the graph's data
    void print_data(void);
    // Perform a dfs from the provided start node. Returns a vector containing
    // the search results
    vector<int> *dfs(int start);
    // perform a bfs from the provided start node. Returns a vector containing
    // the search results
    vector<int> *bfs(int start);
    // Use dijkstra's to find the shortest distance from a source node to 
    // a destination node. Returns the minimum distance between the two or
    // -1 if a path does not exist
    int dijkstra(int, int);
    // construct a MST using primm's algorithm. Returns a vector containing the
    // constructed tree
    vector<int> *primm(int);

private:

};
```

## Building Your Program
GNU Make is used to build our program for us. To support that a complete make
file has already been provided for you. In order to build your program perform
the following steps:
* cd into the source director `cd src`
* Type `make` to build your program.

## Runing unit tests
The unit tests that will be used to grade your program have already been included
in this repo. If you beleive your program to be functioning correctly you may
run them localy in order to verify your programs correctness. To run them, first
`cd` into the tests directory. Then type `make` which will build the unit tests 
for your program, this may take a minute as multiple executables are being compiled. 
Then finally type `./run_tests.sh` to execute the unit tests and report back if they 
passed or failed.

## Deliverables
Commit the final version of your code and push it to the github repository
before the due date of the assignment

## Expections
* No use of any prebuilt graphing libraries
* You _MAY_ use parts of the C++ Standard Template Library such as the stack 
and queue libraries.
* Your code should build and run, no points will be awarded to code that does
not compile
* Your code should be well formatted, points may be taken for sloppy code
* Your code should be fairly robust and be able to handle obvious edge cases such
as calling bfs on a graph when it is empty
* Passing all unit tests does not gaurentee you will be awarded full points for
assignment. Points may be deducted for poor coding practices, unresolved compilation
warnings, poor formatting, or other syntax or semantic errors

## A note on searches
There may be many different valid breadth first or depth first searches on for a 
given graph. How the graph is stored may influence what traversal you get. In order 
to try to standardize the searches it is expected that you will traverse your matrix
from left to right, starting at index 0. If your program is failing unit tests 
but you beleive you are receiving a valid traversal check how you are storing data 
in your data structure.
This repository consists of C++ code to implement the BFS algorithm for the 8-puzzle problem

Dependencies:

System needs to have C++ and g++ compiler installed on it in an Ubuntu Linux environment. All development was done in Ubuntu Linux 16.04.
The following STL libraries need to be included in the headers:
----------------------
#include<vector>
#include<list>
#include<algorithm>
----------------------

Build:

For compiling and executing the code use the following sequence of commands:
~$ g++ --std=c++11 Main.cpp
~$ ./a.out

Input:

For input, enter the vector row-wise into the main function. For instance, if the input is : 
1 2 3
0 4 5
8 6 7

Enter vector<int> puzzle{1,2,3,0,4,5,8,6,7}; into the Main.cpp function.

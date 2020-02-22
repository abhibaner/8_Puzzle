#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <fstream>
#include "Source.h"
#include "Breadth_First_Search.cpp"

using namespace std;



int main() {
	vector<int> puzzle{1,2,3,0,4,5,8,6,7};
	Node prnt = Node(puzzle, NULL);
	prnt.id = -1;
	Node root = Node(puzzle, &prnt);
	root.id = 0;
	
	BFS bfs;

	vector<Node*> solution = bfs.BreadthFirstSearch(&root);




}

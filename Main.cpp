#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <fstream>
#include "Source.h"
#include "Breadth_First_Search.cpp"

using namespace std;



int main(int argc, char* argv[]) {
//	vector<int> puzzle{1,2,3,0,4,5,8,6,7};
	vector<int> puzzle;
	int ctr=1;
	while(ctr!=10){
		int r;
		cout<<"Enter element "<<ctr;
		std::cin>>r;
		puzzle.push_back(r);
		ctr +=1;	
	}
/*
	char trem[9];
	for(int i=0; i<argc;i++){
		trem[i] = *argv[i];
	}
	vector<int> puzzle;
	for(auto i: trem){
		puzzle.push_back(int(i));	
	}
*/		
	Node prnt = Node(puzzle, NULL);
	prnt.id = -1;
	Node root = Node(puzzle, &prnt);
	root.id = 0;
	
	BFS bfs;

	vector<Node*> solution = bfs.BreadthFirstSearch(&root);




}

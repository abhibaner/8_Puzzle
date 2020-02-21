#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include <fstream>
#include "Source.h"
#include "Breadth_First_Search.cpp"

using namespace std;

class BFS {
public:

	BFS() {

	}
	static bool contains(queue<Node*> lst, Node* c) {
		bool contains = false;
		while (!lst.empty()) {
			if (lst.front()->puzzle == c->puzzle)
				contains = true;
			lst.pop();
		}
		return contains;
		
	}

	void pathTrace(vector<Node*> path, Node* n) {
		Node* current = n;
		path.push_back(current);

		while (current->parent != NULL) {
			current = current->parent;
			path.push_back(current);
		}
		std::reverse(path.begin(), path.end());
		cout << "printing solution" << endl;
		for (auto i : path) {
			i->printPuzzle();
			cout << endl;
		}
	}

};


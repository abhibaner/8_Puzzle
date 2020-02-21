#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include "Source.h"

using namespace std;

class BFS {
public:

	BFS() {

	}
	vector<Node*> BreadthFirstSearch(Node* root) {
		vector<Node*> solutionPath;
		queue<Node*> openList;
		queue<Node*> closedList;

		openList.push(root);
		bool goalFound = false;

		while (!openList.empty()>0 && !goalFound) {
			Node* current = openList.front();
			closedList.push(current);
//			openList.pop_back();
			openList.pop();

			current->makeMove();
//			current->printPuzzle();

			for (int i = 0; i < current->children.size(); i++) {

				Node* currentChild = current->children[i];
//				currentChild->printPuzzle();
//				cout << endl;

				if (currentChild->solTest()) {
					
					cout << "Goal found" << endl;
					goalFound = true;
					pathTrace(solutionPath, currentChild);

				}

				if (!contains(openList,currentChild) && !contains(closedList, currentChild)) {
					openList.push(currentChild);
				}
			}
		}

		return solutionPath;
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

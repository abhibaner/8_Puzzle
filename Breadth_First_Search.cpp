#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <fstream>
#include "Source.h"

using namespace std;

class BFS {
public:

	BFS() {

	}

	void printNodes(queue<Node*> expl) {
		ofstream Nodes;
		Nodes.open("Nodes.txt");
		expl.pop();
		int nodeCount = 1;
		while (!expl.empty()) {
			int count = 0;
			Nodes << std::endl;
//			Nodes << "Node number: " << nodeCount;
			for (auto i : convertColumn(expl.front()->puzzle)) {
//				if (count % 3 == 0)
//					Nodes << std::endl;
				Nodes << i << ' ';
				count++;
			}
			Nodes << std::endl;
//			Nodes << "Parent: ";
//			for (auto i : cl.front()->parent->puzzle) {
//				if (count % 3 == 0)
//					Nodes << std::endl;
//				Nodes << i << ' ';
//				count++;
//			}
			expl.pop();
			nodeCount++;
		}
		Nodes.close();
	}


	vector<Node*> BreadthFirstSearch(Node* root) {
		vector<Node*> solutionPath;
		queue<Node*> openList;
		queue<Node*> closedList;
//		unordered_set<Node*> opList;
//		unordered_set<Node*> clList;


		openList.push(root);
//		opList.insert(root);
		bool goalFound = false;

		while (!openList.empty()>0 && !goalFound) {
			Node* current = openList.front();
			closedList.push(current);
//			clList.insert(current);
			openList.pop();
//			opList.erase(opList.begin());

			current->makeMove();
//			current->printPuzzle();
			queue<Node*> temp = current->children;

			while (!temp.empty()) {
				Node* q_element = temp.front();
				if (q_element->solTest()) {
					cout << "Goal Found" << endl;
					goalFound = true;
					pathTrace(solutionPath, q_element);
				}
				if (!contains(openList, q_element) && !contains(closedList, q_element)) {
					openList.push(q_element);
//					opList.insert(q_element);
				}
				temp.pop();

			}
			/*
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
			*/
		}
		printNodes(closedList);
		printInfo(closedList);

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

	void printPath(vector<Node*> pth) {
		ofstream Nodes;
		Nodes.open("nodePath.txt");
		pth.erase(pth.begin());
		int nodeCount = 1;
//		while (!pth.empty()) {
//			int count = 0;
			Nodes << std::endl;
			for (auto i : pth) {
				auto tempr = i->puzzle;
				auto temp = convertColumn(tempr);
				for (int j = 0; j < 9; j++) {
					Nodes << temp[j] << ' ';
//					count++;
				}
				Nodes << std::endl;
//			}
//			Nodes << std::endl;
//			pth.erase(pth.begin());
//			nodeCount++;
		}
		Nodes.close();

	}

	void printInfo(queue<Node*> inf) {
		ofstream Nodes;
		Nodes.open("nodeInfo.txt");
		inf.pop();
		int nodeCount = 1;
		while (!inf.empty()) {
			int count = 0;
			Nodes << std::endl;
			Nodes <<inf.front()->id<<" "<<inf.front()->parent->id<<" "<<'0';
			Nodes << std::endl;
			inf.pop();
			nodeCount++;
		}
		Nodes.close();

	}

	void pathTrace(vector<Node*> path, Node* n) {
		Node* current = n;
		path.push_back(current);

		while (current->parent != NULL) {
			current = current->parent;
			path.push_back(current);
		}
		
		std::reverse(path.begin(), path.end());
		printPath(path);
		cout << "printing solution" << endl;
		for (auto i : path) {
			i->printPuzzle();
			cout << endl;
		}
		printPath(path);
	}

	vector<int> convertColumn(vector<int> pz) {
		vector<int> cpz;
		cpz.push_back(pz[0]);
		cpz.push_back(pz[3]);
		cpz.push_back(pz[6]);
		cpz.push_back(pz[1]);
		cpz.push_back(pz[4]);
		cpz.push_back(pz[7]);
		cpz.push_back(pz[2]);
		cpz.push_back(pz[5]);
		cpz.push_back(pz[8]);

		return cpz;
	}
};

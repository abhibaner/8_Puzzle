#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Node {

public:
	vector<Node*> children;
	Node *parent;
	vector<int> puzzle;
	int x = 0;
	int col = 3;


	Node(vector<int> p, Node * prt) {
		puzzle = p;
		parent = prt;
	}


	bool solTest() {
		/*
		bool isSol = true;

		for (int i = 0; i < 8; i++) {
			if (puzzle[i] > puzzle[i + 1])
				isSol = false;
		}
		*/
		bool isSol = false;
		vector<int> p{ 1,2,3,4,5,6,7,8,0 };
		if (puzzle == p) {
			isSol = true;
		}
		return isSol;
	}

	void copyPuzzle(vector<int> a, vector<int> b) {
		for (int i = 0; i < sizeof(b)/sizeof(int); i++) {
			a[i] = b[i];
		}
	}

	void printPuzzle() {
		int m = 0;
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < col; j++) {
				cout << puzzle[m] << " ";
				m++;
			}
			cout << endl;
		}
	}


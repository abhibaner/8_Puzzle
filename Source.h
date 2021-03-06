#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_


#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;

class Node {

public:
	queue<Node*> children;
	Node *parent;
	vector<int> puzzle;
	int x = 0;
	int col = 3;
	int id;


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

	void moveRight(vector<int> p,int& ctr) {
		int pos = findIndex();
		if (pos != 2 && pos != 5 && pos != 8) {
			vector<int> pcopy = puzzle;
			
			swap(pcopy[pos], pcopy[pos + 1]);
			Node *child = new Node(pcopy, this);
			ctr = ctr + 1;
			child->id = parent->id + ctr;
			children.push(child);
			

		}

	}

	void moveLeft(vector<int> p,int& ctr) {
		int pos = findIndex();
		if (pos != 0 && pos != 3 && pos != 6) {
			vector<int> pcopy = puzzle;

			swap(pcopy[pos], pcopy[pos - 1]);
			Node *child = new Node(pcopy,this);
			ctr = ctr + 1;
			child->id = parent->id + ctr;
			children.push(child);
			

		}
	}

	void moveTop(vector<int> p, int& ctr) {
		int pos = findIndex();
		if (pos != 0 && pos != 1 && pos != 2) {
			vector<int> pcopy = puzzle;

			swap(pcopy[pos], pcopy[pos -3]);
			Node *child = new Node(pcopy,this);
			ctr = ctr + 1;
			child->id = parent->id + ctr;
			children.push(child);

		}
	}

	void moveDown(vector<int> p, int& ctr) {
		int pos = findIndex();
		if (pos != 6 && pos != 7 && pos != 8) {
			vector<int> pcopy = puzzle;

			swap(pcopy[pos], pcopy[pos + 3]);
			Node *child = new Node(pcopy,this);
			ctr = ctr + 1;
			child->id = parent->id + ctr;
			children.push(child);

		}
	}

	bool equalPuzzle(vector<int> arr) {
		bool equalPuzzle = true;
		for (int i = 0; i < 9; i++) {
			if (puzzle[i] != arr[i]) {
				equalPuzzle = false;	
			}
		}
		return equalPuzzle;
	}

	int findIndex() {
		vector<int>::iterator it;
		it = find(puzzle.begin(), puzzle.end(), 0);
		auto z = std::distance(puzzle.begin(), it);
		return (int)z;
	}

	void printInst(vector<int> arr) {
		int m = 0;
		for (int i = 0; i < 3; i++) {
			for (int i = 0; i < 3; i++) {
				cout << puzzle[m] << " ";
				m++;
			}
			cout << endl;
		}

	}

	void makeMove() {
	/*
		for (int i = 0; i < 9; i++) {
			if (puzzle[i] == 0)
				x = i;
			
		}
	*/
		int cnter = 0;
		moveRight(puzzle,cnter);
//		printInst(puzzle);
//		cout << endl;
		moveLeft(puzzle,cnter);

		moveDown(puzzle,cnter);

		moveTop(puzzle,cnter);

	}

};

#endif

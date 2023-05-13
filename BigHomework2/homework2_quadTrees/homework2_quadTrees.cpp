#include <iostream>
#include <list>
#include <stack>
#include <stdexcept> 

using namespace std;

enum Color { black, white, gray };

Color toColor(char chColor) {
	switch (chColor) {
		case 'w': return white;
		case 'b': return black;
		case 'p': return gray;
		default: throw invalid_argument("Invalid color detected");
	}
};

class Node {
public:
	Color color;
	list<Node*> children;

	string colorAsStr() {
		switch (this->color){
			case white: return "white"; 
			case black: return "black";
			default: return "gray";
		}
	}

	Node(Color initialColor) {
		this->color = initialColor;
	}
	~Node() {
		//cout << "node with color '" << colorAsStr() << "' deleted" << endl;
	}
};

class QuadTree {
private:
	Node* root = NULL;

	void freeNodeRec(Node* cur) {
		if (cur == NULL) {
			return;
		}

		for (const auto childNode : cur->children) {
			freeNodeRec(childNode);
		}

		delete cur;
	}

	int countBlackPixelsRec(Node* cur, int dimensionSize) {
		if (cur == NULL) {
			return 0;
		}

		// for 'black' node count pixels in square of size 'dimensionSize'
		if (cur->color == black) {
			return dimensionSize * dimensionSize;
		}
		else if (cur->color == gray) {
			// for 'gray' node check ALL children recursively

			int count = 0;

			for (const auto childNode : cur->children) {
				count += countBlackPixelsRec(childNode, dimensionSize/2);
			}

			return count;
		}

		// for 'white' just return 0
		return 0;
	}

public:
	QuadTree() {
		this->root = NULL;
	}

	/*
	* Create Quad tree from pre-order string
	*/
	QuadTree(string preOrderStr) {
		if (preOrderStr.length() == 0) {
			return;
		}

		stack<Node*> stackData;

		for (const auto nodeColorCh : preOrderStr) {

			Color curColor = toColor(nodeColorCh);
			Node* cur = new Node(curColor);

			if (root == NULL) {
				root = cur;
			}
			else {
				if (stackData.empty()) {
					throw invalid_argument("Incorerct pre-order string passed");
				}

				Node* topParent = stackData.top();

				topParent->children.push_back(cur);

				// top parent value from stack is fully build, 
				// so just remove from stack
				if (topParent->children.size() == 4) {
					stackData.pop();
				}

			}
			// push gray node to stack for processing
			if (curColor == gray) {
				stackData.push(cur);
			}
		}
	}

	int countBlackPixels() {
		return countBlackPixelsRec(root, 32);
	}

	~QuadTree() {
		freeNodeRec(root);
	}


	friend QuadTree mergeTrees(QuadTree first, QuadTree second);

};

/*
* Merge two Quad trees into one
*/
QuadTree mergeTrees(QuadTree first, QuadTree second) {
	QuadTree mergedTree;
	//TODO: merge two quad trees
	return mergedTree;
}

int main(){

	try {
		string preOrderStr1 = "ppwwwbpbbwwbw";
		QuadTree tree1(preOrderStr1);
		cout << "tree1 black pixels count: " << tree1.countBlackPixels() << endl;

		string preOrderStr2 = "pwbwpwwbw";
		QuadTree tree2(preOrderStr2);
		cout << "tree2 black pixels count: " << tree2.countBlackPixels() << endl;

		//QuadTree mergedTree = mergeTrees(tree1, tree2);
		//cout << "mergedTree black pixels count: " << mergedTree.countBlackPixels() << endl;
	}
	catch (const exception& ex) {
		cerr << ex.what() << endl;
	}

	cout << "homework 2 quad trees done" << endl;
	return 0;
}


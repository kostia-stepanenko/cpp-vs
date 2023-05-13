#include <iostream>
#include <vector>
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
	vector<Node*> children;

	string colorAsStr() {
		switch (this->color){
			case white: return "white"; 
			case black: return "black";
			default: return "gray";
		}
	}

	Node* getChildByIndexOrNull(int index) {
		if (index >= 0 && index < this->children.size()) {
			return this->children[index];
		}
		return NULL;
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

	Node* mergeRec(Node* firstNode, Node* secondNode) {
		// nothing left to traverse, so just return
		if (firstNode == NULL && secondNode == NULL) {
			return NULL;
		}

		// first tree completed, so just traverse second
		if (firstNode == NULL) {
			Node* cur = new Node(secondNode->color);

			for (const auto secondChild : secondNode->children) {
				Node* child = mergeRec(NULL, secondChild);
				if (child != NULL) {
					cur->children.push_back(child);
				}
			}

			return cur;
		}

		// second tree completed, so just traverse first
		if (secondNode == NULL) {
			Node* cur = new Node(firstNode->color);

			for (const auto firstChild : firstNode->children) {
				Node* child = mergeRec(firstChild, NULL);
				if (child != NULL) {
					cur->children.push_back(child);
				}
			}

			return cur;
		}

		// firstNode is BLACK OR secondNode is BLACK, return BLACK
		if (firstNode->color == black || secondNode->color == black) {
			return new Node(black);
		}

		// both nodes are WHITE, just return white
		if (firstNode->color == white && secondNode->color == white) {
			return new Node(white);
		}

		// at least one node is GRAY, mark current node as GRAY 
		// and merge all children nodes
		Node* cur = new Node(gray);

		for (int i = 0; i < 4; ++i) {
			Node* child1 = firstNode->getChildByIndexOrNull(i);
			Node* child2 = secondNode->getChildByIndexOrNull(i);
			if (child1 == NULL && child2 == NULL) {
				break;
			}

			cur->children.push_back(mergeRec(child1, child2));
		}


		return cur;
	}

public:

	/*
	* Merge two Quad trees into one
	*/
	QuadTree(const QuadTree& first, const QuadTree& second) {
		root = mergeRec(first.root, second.root);
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
		//cout << "QuadTree destructor called" << endl;
		freeNodeRec(root);
	}

	static string toStringRec(Node* cur) {

		if (cur == NULL) {
			return "";
		}

		string res(cur->colorAsStr() + ", ");

		for (const auto child : cur->children) {
			res += toStringRec(child) + ", ";
		}

		return res;
	};

	friend ostream& operator<<(std::ostream& os, const QuadTree& tree) {
		os << "[" << toStringRec(tree.root) << "]";
		return os;
	}

};

int main(){

	try {

		while (true) {
			string preOrderStr1;
			cout << "Input first tree: ";
			cin >> preOrderStr1;
			QuadTree tree1(preOrderStr1);
			cout << "tree1 black pixels count: " << tree1.countBlackPixels() << endl;
			cout << "=========================================================" << endl;

			string preOrderStr2;
			cout << "Input second tree: ";
			cin >> preOrderStr2;
			QuadTree tree2(preOrderStr2);
			cout << "tree2 black pixels count: " << tree2.countBlackPixels() << endl;
			cout << "=========================================================" << endl;

			cout << "Merging tree 1 and 2" << endl;
			QuadTree mergedTree(tree1, tree2);
			cout << "mergedTree: " << mergedTree << endl;
			cout << "mergedTree black pixels count: " << mergedTree.countBlackPixels() << endl;
			cout << "=========================================================" << endl;

			cout << "Do you want to proceed (Y/N)?: ";
			string proceedAnswer;
			cin >> proceedAnswer;
			if (proceedAnswer == "N") {
				break;
			}
		}
	}
	catch (const exception& ex) {
		cerr << ex.what() << endl;
	}

	cout << "homework 2 quad trees done" << endl;
	return 0;
}


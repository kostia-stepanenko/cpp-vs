// binary-serach-tree-home.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


template<typename T> class Node {

public:
    Node* left;
    Node* right;
    T value;

    Node(int newValue) :value(newValue), left(NULL), right(NULL) {}

};

template<typename T> class BSTree {

/*
===============================================================================
PRIVATE section
===============================================================================
*/
private:

    void inOrderRec(Node<T>* cur) {
        if (cur == NULL) {
            return;
        }

        inOrderRec(cur->left);

        cout << cur->value << ", ";

        inOrderRec(cur->right);
    }

    void preOrderRec(Node<T>* cur) {
        if (cur == NULL) {
            return;
        }
        cout << cur->value << ", ";

        preOrderRec(cur->left);

        preOrderRec(cur->right);
    }

    void   printLeafNodesRec(Node<T>* cur) {
        if (cur == NULL) {
            return;
        }
        if (cur->left == NULL && cur->right == NULL) {
            cout << cur->value << ", ";
        }
        if (left != NULL) {
            printLeafNodesRec(cur->left);
        }
        if (right != NULL) {
            printLeafNodesRec(cur->right);
        }
    }

/*
===============================================================================
PUBLIC section 
===============================================================================
*/
public:
    Node<T>* root = NULL;

    bool add(T value) {
        if (root == NULL) {
            root = new Node<T>(value);
            return true;
        }

        Node<T>* parent = root;
        Node<T>* cur = root;

        while (cur != NULL) {
            if (cur->value == value) {
                return false;
            }

            // go right node
            else if (value > cur->value) {
                parent = cur;
                cur = cur->right;
            }

            // go left node
            else {
                parent = cur;
                cur = cur->left;
            }
        }

        if (value < parent->value) {
            parent->left = new Node<T>(value);
        }
        else {
            parent->right = new Node<T>(value);
        }

        return true;

    }

    void inOrderPrint() {
        inOrderRec(root);
        cout << endl;
    }

    void preOrderPrint() {
        preOrderRec(root);
        cout << endl;
    }

    void printLeafNodes() {
        printLeafNodesRec(root);
        cout << endl;
    }

    T findMin() {
       
        if (root == NULL) {
            cerr << "Error:empty tree";
            return -1;
        }
        
        Node<T>* cur = root;

            while (cur->left != NULL) {
                cur = cur->left;
               
            }
        return cur->value;
    }

    T findMax() {

        if (root == NULL) {
            cerr << "Error:empty tree";
            return -1;
        }

        Node<T>* cur = root;

        while (cur->right != NULL) {
            cur = cur->right;

        }
        return cur->value;
    }

};

int main()
{

    BSTree<int> tree;

    tree.add(10);
    tree.add(20);
    tree.add(7);
    tree.add(15);
    tree.add(4);
    tree.add(1);
    tree.add(37);

    tree.inOrderPrint();
    tree.preOrderPrint();
    tree.printLeafNodes();


    cout << "Binary Search tree done..." << endl;
    cout << " Min value is: " << tree.findMin() << endl;
    cout << " Max value is: " << tree.findMax() << endl;
};



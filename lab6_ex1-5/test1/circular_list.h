#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//doubly linked list

template <typename T>
struct CircularNode
{ //structure for a list's node; it has the node's info and 2 pointers
    T info;
    CircularNode <T> *next; //pointer to the next node
    CircularNode <T> *prev; //pointer to the previous node
};

template <typename T>
class CircularList
{
    public:
        CircularNode <T> *pfirst; //pointer to the first node
        CircularNode <T> *plast; //pointer to the last node

    void addLast(T x)
    {
        //add info x on the last position of the list

        CircularNode<T>* cur = new CircularNode <T>;

        cur->info = x;
        cur->prev = plast;
        cur->next = NULL;

        if (pfirst == NULL) {
            pfirst = plast = cur;
            cur->next = cur;
            cur->prev = cur;
        }
        else {
            plast->next = cur;
            cur->prev = plast;
            plast = cur;
            cur->next = pfirst;
            pfirst->prev = cur;
        }   
    }

    void printList() {

        cout << "the list is: ";

        if (pfirst == NULL) {
            return;
        }

        cout << pfirst->info << ", ";

        CircularNode <T>* cur = pfirst->next;
        
        while (cur != pfirst)
        {
            cout << cur->info << ", ";
            cur = cur->next;

        }
        cout << endl;
    }

    void printListReverse() {
        cout << "the reversed list is: ";
        if (pfirst == NULL) {
            return;
        }
        cout << plast->info << ", ";

        CircularNode <T>* cur = plast->prev;

        while (cur != plast)
        {
            cout << cur->info << ", ";
            cur = cur->prev;

        }
        cout << endl;
    }

    int isEmpty()
    { //check if the list is empty
        return (pfirst == NULL);
    }

    CircularList()
    { //constructor
        pfirst = plast = NULL;
    }

    ~CircularList()
    {


    }

};


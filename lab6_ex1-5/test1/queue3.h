#include <stdio.h>
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T> class LinkedQueue {

private:
    LinkedList<T> list;
    int size;

public:

    void enqueue(T x) {
        list.addLast(x);
        ++size;
    }

    T dequeue() {

        if (isEmpty()) {
            throw invalid_argument("Can't dequeue element from empty queue");
        }

        T elem = list.pfirst->info;

        list.removeFirst();
        --size;

        return elem;
    }

    T peek() {
        if (isEmpty()) {
            return NULL;
        }

        return list.pfirst->info;
    }

    int isEmpty() {
        return list.isEmpty();
    }

    int getSize() {
        return size;
    }

    LinkedQueue(){
        size = 0;
    }
    ~LinkedQueue() {}
};



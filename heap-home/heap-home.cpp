// heap-home.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

template <typename T> class MaxHeap {

private:
    T* arr;
    int last;


    void fixUp(int index) {

        if (index == 0) {
            return;
        }

        int parent = ceil((double)index / 2.0) - 1;

        if (arr[parent] < arr[index]) {
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
            fixUp(parent);
        }
    }

    void fixDown(int index) {
        if (index > last) {
            return;
        }

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int maxIndex = index;

        if (arr[left] > arr[maxIndex]) {
            maxIndex = left;
        }
            
        if (arr[right] > arr[maxIndex]) {
            maxIndex = right;
        }

        if (index == maxIndex) {
            return;
        }

        T temp = arr[index];
        arr[index] = arr[maxIndex];
        arr[maxIndex] = temp;

        fixDown(maxIndex);
    }

public:
    MaxHeap() {
        arr = new T[1000];
        last = -1;
    }

    ~MaxHeap() {
        delete[] arr;
    }

    void add(T value) {
        ++last;
        arr[last] = value;
        fixUp(last);
    }

    T maxValue() {
        return arr[0];
    }

    T extractMax() {

        T value = arr[0];

        arr[0] = arr[last];
        arr[last] = NULL;
        --last;

        fixDown(0);


        return value;
    }

    int size() {
        return last + 1;
    }





};

void findMinValue(int arr[], int length, int quantity) {
    MaxHeap<int> heap;

    for (int i = 0; i < quantity; i++) {
        heap.add(arr[i]);
    }

    for (int i = quantity; i < length; i++) {

        int maxInHeap = heap.maxValue();

        if (maxInHeap > arr[i]) {
            heap.extractMax();
            heap.add(arr[i]);
        }
    }
    while (heap.size() > 0) {
        cout << heap.extractMax() << endl;
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

void reverse(int arr[], int length) {
    reverse(arr, arr + length);
}

int main()
{ 
    int arr[] = { 5,4,3,10,12,6,7,1,8,22};

    int length = sizeof(arr)/sizeof(int);

    findMinValue(arr, length, 3);
    /*
    MaxHeap<int> heap;

    int length = 5;
    int arr[] = {3,9,5,12,20};
   
    for (int i = 0; i < length; i++) {
        heap.add(arr[i]);    
    }
   
    for (int i = length - 1; i >= 0 && heap.size() > 0; --i) {
        arr[i] = heap.extractMax();
    }

    printArray(arr, 5);
    */
}

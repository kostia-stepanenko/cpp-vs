#include <iostream>
using namespace std;




// random number
  // int random = rand();



void fillRandom(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i]= rand();
    }
};


void printArray(int arr[], int length) {

    for (int i = 0; i < length; i++) {
        cout << arr[i] << ", ";
    }

    cout << endl;

}

int* sum(int arr1[], int length1, int arr2[], int length2) {

    int sumLength = std::max(length1, length2);
    int* sum = new int[sumLength];

    for (int i = 0; i < sumLength; ++i) {


        int first = (i < length1) ? arr1[i] : 0;
        int second = (i < length2) ? arr2[i] : 0;

        sum[i] = first + second;

    }

    return sum;
}

int main()
{

    int length1;
    int length2;

    cout << "Enter the size of first array:" << "\n";
    cin >> length1;

    cout << "Enter the size of second array:" << "\n";
    cin >> length2;

    int* arr1 = new int[length1];
    int* arr2 = new int[length2];

    
    fillRandom(arr1, length1);
    fillRandom(arr2, length2);

    printArray(arr1, length1);
    printArray(arr2, length2);


    int* sumArr = sum(arr1, length1, arr2, length2);

    printArray(sumArr, std::max(length1, length2));

    delete[] sumArr;
    delete[] arr1;
    delete[] arr2;

    return 0;
}
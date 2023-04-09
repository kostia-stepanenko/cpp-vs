#include <iostream>

using namespace std;

class User {
private:
    string name;
    int age;

public:
    User(string name, int age) {
        this->name = name;
        this->age = age;
    }

    User() {
        this->name = "unknown";
        this->age = 0;
    }

    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }


    void setAge(int x) {
        this->age = x;
    }

    void setName(string x) {
        this->name = x;
    }
};



void printArray(User arr[], int length) {


    for (int i = 0; i < length; i++) {
        cout <<  arr[i].getAge() <<" " << arr[i].getName() <<endl;
    }

}


int main()
{
    
     int size;
    cout << "Enter the number of Users:" << "\n";
    cin >> size;


    User* arr = new User[size];
   
    for (int i = 0; i < size; i++) {
        cout << "Enter User-" << (i+1) <<" name: ";
        string name;
        cin >> name;

        cout << "Enter User-" << (i + 1) << " age: ";
        int age;
        cin >> age;

        arr[i].setName(name);
        arr[i].setAge(age);
    }

    printArray(arr, size);

    delete[] arr;

}



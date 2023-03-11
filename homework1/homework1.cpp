#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

bool is_palindrome(int value);

int main()
{

    cout << "Input value to check for palindrome: ";

    int value1;
    string line;

    getline(cin, line);

    stringstream ss(line); 

        if (ss >> value1 && ss.eof()) {
            if (is_palindrome(value1)) {
                cout << value1 << " is Palindrome" << endl;
            }
            else {
                cout << value1 << " is not Palindrome" << endl;
            }
        }
        else {
            cerr << "Not a number: " << line << endl;
        }

    return 0;
}


bool is_palindrome(int value) {

    string str_val = to_string(value);
    reverse(str_val.begin(), str_val.end());

    return str_val == to_string(value);
}

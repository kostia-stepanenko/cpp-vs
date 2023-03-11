#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;



struct date {
    unsigned int day;
    unsigned int month;
    int year;
};

bool is_valid(date date_to_check) {


    int day = date_to_check.day;
    int month = date_to_check.month;
    int year = date_to_check.year;
    if (day <= 0 || day > 31) return false;
    if (month == 2 && year % 4 == 0 && day > 29) return false;
    if (month == 2 && year % 4 != 0 && day > 28) return false;

    if (day == 0) return false;
    if (month == 0) return false;
    if (month != 2) {
        if (month == 1, month == 3, month == 7, month == 8) {
            if (day > 31)return false;
        }
        else {
            if (day > 30) return false;

        }
    }
    if (month > 12) return false;

    return true;
}

int main()
{
    date my_date;
    cout << "Input a  date" << endl;
    cin >> my_date.day >> my_date.month >> my_date.year;
    if (is_valid(my_date)) {
        cout << " true" << endl;
    }
    else cout << "false" << endl;

}


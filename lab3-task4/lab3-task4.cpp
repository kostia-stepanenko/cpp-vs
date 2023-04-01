
#include <iostream>
#include "stack.h"
    using namespace std;

    
    Stack <double> st;

  
    void push_digits(int number)
    {
        while (number != 0)
        {
            st.push(number % 10);
            number = number / 10;
        }
    }

    
    double reverse_number(double number)
    {
        
        push_digits(number);

        int reverse = 0;
        int i = 1;

        
        while (!st.isEmpty())
        {
            reverse = reverse + (st.peek() * i);
            st.pop();
            i = i * 10;
        }

       
        return reverse;
    }

    
    int main()
    {
        double number;
      
       
    
           
            cin >> number;
        
        cout << reverse_number(number);

        return 0;
    }




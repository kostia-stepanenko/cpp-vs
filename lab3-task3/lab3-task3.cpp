#include <iostream>
#include "stack.h"
using namespace std;
int main()
{

    Stack <int> s;
    cout << s.isEmpty() << endl;
    s.push(9);
    cout << s.isEmpty() << endl;
    s.push(7);
    s.push(3);
    s.push(5);
   // cout << s.peek() << endl;
  //  s.pop();
    s.peek();
  //  cout << s.peek() << endl;
    s.display();
    return 0;
}
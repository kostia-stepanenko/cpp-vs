
#include <iostream>
#include "queue4.h"
#include "mystack1.h"

using namespace std;
template<typename T>

class StackedQueue {
private:
	Stack <T> s1, s2;
	

public:
	StackedQueue(){}

	void enqueue(T x) {

		s1.push(x);
	}
	int isEmpty() {
		return s1.isEmpty();
	}
	T dequeue() {
		for (int i = s1.getTopLevel() -1; i>=0 ; i--)
		{
			s2.push(s1.pop());
		}
		T aux;
		aux = s1.pop();
		for (int i = 0; i < s2.getTopLevel()+1; i++) 
		{
			s1.push(s2.pop());
		}
		return aux;
	}


};
int main()
{
	StackedQueue <int> s1;
	s1.enqueue(1);
	s1.enqueue(4);
	s1.enqueue(6);
	s1.enqueue(9);
	cout << s1.isEmpty() << endl;
	cout << s1.dequeue() << endl;
	cout << s1.isEmpty() << endl;
	cout << s1.dequeue() << endl;
	cout << s1.isEmpty() << endl;
	cout << s1.dequeue() << endl;
	cout << s1.dequeue() << endl;
	cout << s1.isEmpty() << endl;
}



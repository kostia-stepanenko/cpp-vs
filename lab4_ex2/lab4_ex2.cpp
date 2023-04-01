

#include <iostream>
#include "queue3.h" 

using namespace std;

template <typename T>

class QueuedStack {
private:
	QueueCirc <T> q1, q2;
public:
	QueuedStack() {};
	
	void push(T x) 
	{
		q1.enqueue(x);
	}
	int isEmpty()
	{
		return q1.isEmpty();

	}
	T pop() 
	{
		int s = q1.getSize();
		for (int i = 0; i <= s-2; i++) {
			q2.enqueue(q1.dequeue());
		}

		T aux = q1.dequeue();
		for (int i = 0; i <s-2; i++) {
			q1.enqueue(q2.dequeue());
		}
		return aux;
	}
};

int main()
{
	QueuedStack <int> q1;
	

	q1.push(8);
	q1.push(4);
	q1.push(2);
	q1.push(1);
	q1.push(10);

	if (q1.isEmpty()) 
		cout << "is empty" << endl;
	else cout << "is not empty" << endl;
	cout << q1.pop() << endl;
}



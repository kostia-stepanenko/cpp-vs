
#include <iostream>

using namespace std;

void reverseArr(int* a, int n) {
	int x;
	int *p{};
	for (int i = 0; i < n / 2; i++) {
		x = *(p + i);
		*(p + i) = *(p + n - 1 - i);
		*(p + n - 1 - i) = x;
	}

	
}
int main()
{
  
	int *p;
	int a[6];
	p = &a[0];
	for (int i = 0; i <= 5; i++) {
		cin >> *(p + i);
	}
	/*
	for (int i = 0; i <= 5; i++) {
		cout << a[i] << "";
		
	}
	
	cout << endl;
	
	for (int i = 5; i >=0; i--) {
		cout << *(p + i)<<"";
	}
	*/
	reverseArr(p,6);
	for (int i = 0; i <= 5; i++) {
		cout << a[i] << "";

	}
	
	return 0;
}

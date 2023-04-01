#include <iostream>
using namespace std;




	template <typename T> void sort(T* v, int length)
	 {
	
			for (int i = 0; i < length - 1; i++) { // slots

				for (int j = i + 1; j < length; ++j) {
					if (v[i] > v[j]) {
						swap(v[i], v[j]);
					}
				}
			}
	}


	template <typename T> void sort_reverse(T* v, int length)
	{
		for (int i = length-1; i > 0; i--) {
			for (int j = i - 1; j >= 0; --j) {
				if (v[j] > v[i]) {
					swap(v[i], v[j]);
				}
			}
		}
	}

	template <typename T> void reverse_order(T* v, int length)
	{
		int i = 0;
		int j = length - 1;

		while ( i < j ){
			swap(v[i], v[j]);

			i++;
			j--;
		}; 
				
	}




template <typename T> void print_array(T* v, int length) {
	for (int i = 0; i < length; i++) {
		cout << v[i] << ", ";
	}

	cout << endl;
}



int main()
{
	int length;

	cout << "Input srray length: ";
	cin >> length;

	if (length < 0) {
		cerr << "Array length csn't be negative" << endl;
		return -1;
	}

	int* arr = new int[length];


	for (int i = 0; i < length; ++i) {
		cin >> arr[i];
	}

	print_array(arr, length);

	//sort(arr, length);
	//sort_reverse(arr, length);
	reverse_order(arr, length);

	print_array(arr, length);

	delete[] arr;	
}


#include <iostream>
using namespace std;


char* getDep(char* p) {

	while ( *p != NULL && *p != ' ') {
		++p;
	}

	if (*p == NULL) {
		cerr << "not found" << endl;
		return p;
	}

	++p;
	return p;
	
}

void commaReplacer(char* p) {
	while (*p != NULL) {
		if (*p == ',') {
			*p = ' ';
		}
		p++;
	}
}

void fillMe(int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		arr[i] = i;
	}
}

void doubleMe(int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		arr[i] *= 2;
	}
}

void printMe(int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		cout << arr[i] << ", ";
	}

	cout << endl;
}

void swap(char* first, char* second) {
	char temp = *first;
	*first = *second;
	*second = temp;
}

void reverse(char* arr) {
	
	char* start = arr;
	char* end= arr;

	while (*end != NULL) {
		end++;
	}
	end--;


	while (start < end ) {
		swap(start, end);
		++start;
		--end;
	}
}

void reverseArray(int arr[], int length) {
	int* start = arr;
	int* end = arr;

	for (int i = 0; i < length-1; ++i) {
		++end;
	}

	while (start < end) {

		int temp = *start;
		*start = *end;
		*end = temp;

		++start;
		--end;
	}

}


int main()
{
	/*
	char s[] = "Slatina, OT";

	cout << "'" << getDep(s) << "'" << endl;

	cout << s << endl;
	*/

	/*
	char s[] = "Hello,World,nice,to,meet,you.";

	commaReplacer(s);

	cout << s << endl;
	*/


	// reverse char array
	char str[] = "hell";
	reverse(str);

	cout << str << endl;

	
	/*
	int length;

	cout << "input array length: ";
	cin >> length;

	int* arr = new int[length];

	for (int i = 0; i < length; ++i) {
		cin >> arr[i];
	}

	reverseArray(arr, length);

	printMe(arr, length);


	delete[] arr;
	*/

	
	return 0;
}



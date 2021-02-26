/* V2. (dog)English(maybe) version */

// Libraries
#include <iostream>
using namespace std;

// Function Signatures
void fillArray(int *arr, int size);
bool search(int *arr, int size, int key);
void printArray(int *arr, int size);

// Main
int main()
{
	/* Khai bao va khoi tao */
	//const int NUMBER = 5; // Unused
	int NUMBER = 0;
	cout << "Nhap so luong phan tu trong mang: ";
	cin >> NUMBER;
	
	int *arr = new int[NUMBER]; // Remember to delete it!
	int key = 0;
	
	/* Fill, print and search the Array */
	fillArray(arr, NUMBER);
	printArray(arr, NUMBER);
	cout << "Nhap so can tim: ";
	cin >> key;
	bool result = search(arr, NUMBER, key);

	if (result)
	{
		cout << "There is " << key << " in the Array.\n";
	}
	else
	{
		cout << "The is no " << key << " in the Array.\n"; 
	}

	/* End of program */
	delete [] arr; // Delete the pointer.
	return main(); // Restart the program. Ctrl + C to end. Otherwise replace this with "return 0;"

}

// Functions
void fillArray(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "Input the " << i << " numbered element : ";
		int temp = 0;
		cin >> temp;
		arr[i] = temp;
		cout << endl;
	}
}

void printArray(int arr[], int size)
{
	cout << "Elements of the Array: ";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


bool search(int *arr, int size, int key)
{	
	int temp = 0;
	while(temp != size)
	{
		if (arr[temp] == key)
		{
			return true;
		}
		++temp;
	}

	return false;
}

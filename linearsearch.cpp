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
	const int NUMBER = 5;
	int *arr = new int[NUMBER];
	int key = 0;
	
	fillArray(arr, NUMBER);
	printArray(arr, NUMBER);
	cout << "Input key: ";
	cin >> key;
	bool result = search(arr, NUMBER, key);

	if (result)
	{
		cout << "Co " << key << " ton tai trong mang.\n";
	}
	else
	{
		cout << "Khong co " << key << " o trong mang.\n"; 
	}

	delete [] arr;
	return main();

}

// Functions
void fillArray(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "Nhap phan tu thu " << i << " : ";
		int temp = 0;
		cin >> temp;
		arr[i] = temp;
		cout << endl;
	}
}

void printArray(int arr[], int size)
{
	cout << "Cac phan tu trong mang: ";
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

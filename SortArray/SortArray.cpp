#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <iterator> 
using namespace std;

int main()
{
	int size = 0;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << size << " ";
	sort(arr, arr + size);
	for (int i = 0; i < size - 1; ++i)
		cout << arr[i] << " ";
	cout << arr[size - 1];
	//delete arr;
	return 0;
}
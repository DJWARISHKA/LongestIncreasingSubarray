#include <iostream>
using namespace std;

int find(int size) {
	int max = 1, now = 1;
	int* arr = new int[size];
	cin >> arr[0];
	for (int i = 1; i < size; i++)
	{
		cin >> arr[i];
		if (arr[i] - arr[i - 1] == 1) {
			now++;
		}
		else {
			now = 1;
		}
		if (now > max)
			max = now;
	}
	delete arr;
	return max;
}
int main() 
{
	int size = 0;
	cin >> size;
	cout << find(size);
	return 0;
}
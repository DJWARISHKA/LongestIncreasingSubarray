#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
	list <int> _list1, _list2;
	list <int> ::iterator it;
	list <int> ::iterator it1;
	list <int> ::iterator it2;
	int buf = 0;
	cin >> buf;
	while (buf != -1)
	{
		_list1.push_back(buf);
		cin >> buf;
	}
	cin >> buf;
	while (buf != -1)
	{
		_list2.push_back(buf);
		cin >> buf;
	}
	for (it = _list2.begin(); it != _list2.end(); ++it)
	{
		buf = *it;
		it1 = _list1.end();
		it2 = --it1;
		for (int i = _list1.size() - 1; i > 0; i--) {
			it1--;
			if (int(i / buf)*buf == i)
				_list1.erase(it2);
			it2 = it1;
		}
		_list1.pop_front();
	}
	for (it = _list1.begin(); it != _list1.end(); ++it)
		cout << *it << " ";
	cout << -1;
	_list1.clear();
	_list2.clear();
	return 0;
}
#include "stdafx.h"
#include <iostream>

using namespace std;

class Shortset {
private:
	bool x[65535];
	int y[65535];

public:
	Shortset() {
		for (int i = 0; i < sizeof(x) / sizeof(*x); i++) {
			x[i] = false;
			y[i] = 0;
		}
	};
	bool empty();
	void insert(short x);
	bool find(short x);
	void erase(short x);
	int size();
protected:
	void quickSort(int l, int r) {
		int x = y[l + (r - l) / 2];
		int i = l;
		int j = r;

		while (i <= j) {
			while (y[i] < x)i++;
			while (y[j] > x)j--;
			if (i <= j)
			{
				int swap = 0;
				swap = y[i];
				y[i] = y[j];
				y[j] = swap;
				i++;
				j--;
			}
		}
		if (i < r)
			quickSort(i, r);
		if (l < j)
			quickSort(l, j);
	}

};

int Shortset::size() {
	int size = 0;
	for (int i = 0; i < (sizeof(x) / sizeof(*x)); i++) {
		if (x[i] == true)
			size++;
		if (x[i] == false)
			break;
	}
	return size;
}
bool Shortset::empty() {
	bool z;
	for (int i = 0; i < size() + 1; i++) {
		if (x[i] == true) {
			z = true;
			break;
		}
		else {
			z = false;
			break;
		}
	}
	return z;
}

bool Shortset::find(short key) {
	int left = 0, right = size(), mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (key < y[mid])
			right = mid - 1;
		else
			if (key > y[mid])
				left = mid + 1;
			else
				return x[mid];
	}
	return 0;
}
void Shortset::erase(short _X) {
	int left = 0, right = size(), mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (_X < y[mid])
			right = mid - 1;
		else
			if (_X > y[mid])
				left = mid + 1;
			else {
				y[mid] = y[size() - 1];
				y[size() - 1] = 0;
				x[size() - 1] = false;
			}
	}
	quickSort(0, size() - 1);
}
void Shortset::insert(short _X) {
	y[size()] = _X;
	x[size()] = true;
	if (size() > 1)
		quickSort(0, size() - 1);
}




int main() {
	Shortset a;
	cout << a.empty() << endl;
	cout << a.size() << endl;
	a.insert(43);
	a.insert(10);
	a.insert(53);
	a.insert(44);
	a.insert(45);
	a.insert(46);
	cout << a.empty() << endl;
	cout << a.size() << endl;
	cout << a.find(100) << endl;
	cout << a.find(10) << endl;
	a.erase(44);
	cout << a.find(44) << endl;
	cout << a.size() << endl;
	system("pause");
}

#include<iostream>
#include<vector>
using namespace std;

//1) Select one element in the middle of the vector. We call it pivot.
//2) Every elements smaller than the pivot come before, and after the pivot bigger elements follow.
//3) For two separated lists, you repeat the process recursively until the size of lists become 0 or 1.


int v[1000000];

void swap(int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}

int choosePivot(int low, int high) {
	return low + (high - low) / 2;
}

int partition(int low, int high) {
	int pivotIndex = choosePivot(low, high);
	int pivotValue = v[pivotIndex];
	swap(v[pivotIndex], v[high]);
	int storeIndex = low;
	for (int i = low; i < high; i++) {
		if (v[i] < pivotValue) {
			swap(v[i], v[storeIndex]);
			storeIndex++;
		}
	}
	swap(v[storeIndex],v[high]);
	return storeIndex;
}

void quicksort(int low, int high) {
	if (low < high) {
		int pivot = partition(low, high);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	quicksort(0,n-1);
	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
}
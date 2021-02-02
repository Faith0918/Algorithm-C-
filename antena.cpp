#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int a;
	vector<int> v;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int b;
		cin >> b;
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	cout << v[(a / 2)-1];
}
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	string a[1001];
	for (int i = 0; i < s.size(); i++) {
		a[i] = s.substr(i);
	}
	sort(a, a + s.size());
	for (int i = 0; i < s.size(); i++) {
		cout << a[i] << "\n";
	}
}
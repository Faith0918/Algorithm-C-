#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> s;
	int a, b, m;
	cin >> a >> b;
	cin >> m;
	int arr[26] = {};
	for (int i = m-1; i >= 0; i--) {
		cin >> arr[i];
	}
	int base10 = 0;
	int base = 1;
	for (int i = 0; i <= m - 1; i++) {
		base10 += base * arr[i];
		base *= a;
	}
	int q, r;
	while (base10 != 0) {
		q = base10 / b;
		r = base10 % b;
		s.push(r);
		base10 = q;
	}
	while (!s.empty()) {
		cout << s.top()<<" " ;
		s.pop();
	}
}
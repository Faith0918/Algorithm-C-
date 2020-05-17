#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n,q,r;
	cin >> n;
	stack<int> s;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (n != 0) {
		if (n > 0) {
			q = n / -2;
			r = n % -2;
			s.push(r);
			n = q;
		}
		else if (n < 0) {
			q = (-n) / 2;
			r = (-n) % 2;
			if (r > 0) {
				q++;
			}
			s.push(r);
			n = q;
		}
		
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}
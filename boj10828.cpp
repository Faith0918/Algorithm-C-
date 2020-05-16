#include<iostream>
#include<stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	string cmd;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			s.push(x);
		}
		else if (cmd == "pop") {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (cmd == "size") {
			cout << s.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << s.empty() << "\n";
		}
		else if (cmd == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}
	}
}

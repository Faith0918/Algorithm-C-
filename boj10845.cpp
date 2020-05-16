#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			cin >> x;
			q.push(x);
		}
		else if (s == "pop") {
			cout << q.front() << "\n";
			q.pop();
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			cout << q.front() << "\n";
		}
		else if (s == "back") {
			cout << q.back() << "\n";
		}
	}
}
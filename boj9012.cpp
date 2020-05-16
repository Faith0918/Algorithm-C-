#include<iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int open = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ')') {
				if (open == 0) {
					cout << "NO" << "\n";
					break;
				}
				else {
					open--;
				}
			}
			else if (s[j] == '(') {
				if (j == s.size() - 1) {
					cout << "NO" << "\n";
					break;
				}
				else {
					open++;
				}
			}
			if (j == s.size()-1 ) {
				if (open == 0) {
					cout << "YES" << "\n";
				}
				else {
					cout << "NO" << "\n";
				}
			}
			
		}
	}
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int SIZE = s.size();
	vector<int> v(SIZE);
	int answer = 0;
	for (int i = 0; i < SIZE; i++) {
		int num = s[i] - '0';
		if (answer < 2) {
			answer += num;
		}
		else {
			answer *= num;
		}
	}
	cout << answer;
}
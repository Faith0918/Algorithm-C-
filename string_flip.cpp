#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int SIZE = s.size();
	int zero = 0;
	int one = 0;
	int cur_state;
	int dif_cnt=0;
	cur_state = s[0] - '0';
	if (cur_state = 0) {
		zero++;
	}
	else {
		one++;
	}
	for (int i = 1; i < SIZE; i++) {
		if (s[i] - '0' != cur_state) {
			if (cur_state == 0) {
				one++;
			}
			else {
				zero++;
			}
			cur_state = s[i] - '0';
		}
	}
	cout << min(one, zero);
}
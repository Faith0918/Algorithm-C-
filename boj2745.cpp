#include<iostream>
#include<stack>
using namespace std;

long long char_to_long(char c) {
	long long A = 'A' - 0;
	long long one = '1' - 0;
	if (c >= 'A' && c <= 'Z') {
		return c - 0 - A + 10;
	}
	else {
		if (c == '0') {
			return 0;
		}
		else {
			return c - 0 - one+1;
		}
	}
}
int main() {
	string s;
	long long b;
	long long ret = 0;
	long long base = 1;
	cin >> s >> b;
	for (int i = s.size()-1; i >=0; i--) {
		//cout << "base : " << base<<endl;
		long long number = char_to_long(s[i]);
		ret += (number)*base;
		base *= b;
	}
	cout << ret;

}
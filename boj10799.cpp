#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int count = 0;
	int ret = 0;
	int i = 0;
	while(i<s.size()) {
		if (s[i] == '(') {
			if (s[i + 1] == ')') {
				ret += count;
				
				cout << "000 i : " << i << "\n";
				i = i + 2;
			}
			else {
				cout << "111 i : " << i << "\n";
				count++;
				i = i + 1;
			}
			
		}
		else if (s[i] == ')' ) {
			ret++;
			count--;
			cout << "222 i : " << i << "\n";
			i = i + 1;
		}
	}
	
	cout << ret << "\n";
	
}
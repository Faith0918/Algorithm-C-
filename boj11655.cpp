#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] < 'a'+13) {
				s[i] = (s[i] + 13);
				
			}
			else if (s[i] >= 'a'+13 && s[i] <= 'z') {
				s[i] = (s[i] - 13);

			}
			else if (s[i] >= 'A' && s[i] <'A'+13) {
				s[i] = (s[i] + 13);
				
			}
			else if (s[i] >= 'A' + 13 && s[i] <= 'Z') {
				s[i] -= 13;
			}
		}
		cout << s;
	}
}
#include<iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	char alphabet[26] = { 'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int ans[26] = {};
	for (int i = 0; i < 26; i++) {
		bool in_s = false;
		for (int j = 0; j < s.size(); j++) {
			if (alphabet[i] == s[j]) {
				in_s = true;
				ans[i] = j;
				break;
			}
		}
		if (!in_s) {
			ans[i] = -1;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << ans[i] << " ";
	}
}
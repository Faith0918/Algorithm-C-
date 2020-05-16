#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	char alphabet[26] = { 'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int ans[26] = {};
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (alphabet[j] == s[i]) {
				ans[j]++;
				break;
			}
		}
	}
	for (int i = 0; i < 25; i++) {
		cout << ans[i] << " ";
	}
	cout << ans[25];

}
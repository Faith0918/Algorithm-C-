#include<iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s[0] >= '4') {
		if (s[0] == '7') {
			cout << "111";
		}
		else if (s[0] == '6') {
			cout << "110";
		}
		else if (s[0] == '5') {
			cout << "101";
		}
		else {
			cout << "100";
		}
	}
	else if (s[0] >= '2') {
		if (s[0] == '3') {
			cout << "11";
		}
		else {
			cout << "10";
		}
	}
	else {
		if (s[0] == '1') {
			cout << "1";
		}
		if (s.size() == 1 && s[0] == '0') {
			cout << "0";
		}
	}
	for (int i = 1; i < s.size(); i++) {
		int one = '1' - '0';
		int number;
		if (s[i] == '0') {
			number = 0;
		}
		else {
			number = s[i] - '0' - one + 1;
		}
		switch (number)
		{
		case 0: cout << "000"; break;
		case 1: cout << "001"; break;
		case 2: cout << "010"; break;
		case 3: cout << "011"; break;
		case 4: cout << "100"; break;
		case 5: cout << "101"; break;
		case 6: cout << "110"; break;
		case 7: cout << "111"; break;
		default:
			break;
		}
	}

}
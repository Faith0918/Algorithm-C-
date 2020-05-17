#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int a, b;
	int gd, lm;
	cin >> a >> b;
	gd = 1;
	lm = a * b;
	for (int i = a * b; i >= max(a, b); i--) {
		if (i % a == 0 && i % b == 0 && i < lm) {
			lm = i;
		}
	}
	for (int i = 1; i <= min(a, b); i++) {
		if (a % i == 0 && b % i == 0 && gd < i) {
			gd = i;
		}
	}
	cout << gd << endl;
	cout << lm << endl;
}
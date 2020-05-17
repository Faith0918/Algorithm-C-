#include<iostream>

using namespace std;

bool sosu(int i) {
	if (i == 1) {
		return false;
	}
	bool is_divided = false;
	for (int j = 2; j < i; j++) {
		if (i % j == 0) {
			is_divided = true;
			break;
		}
	}
	return !is_divided;
}
int main() {
	int n;
	int ret = 0;
	int a[101] = {};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (sosu(a[i])) {
			ret++;
		}
	}
	cout << ret;
}
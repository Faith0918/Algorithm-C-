#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int gcd(int a, int b) {
	int maxx = 0;
	for (int i = 1; i <= min(a, b); i++) {
		if (a % i == 0 && b % i == 0 && i > maxx) {
			maxx = i;
		}
	}
	return maxx;
}
int main(){
	int t, a, b;
	cin >> t ;
	for (int i = 1; i <= t; i++) {
		int ret = 1;
		cin >> a >> b;
		ret = gcd(a, b);
		ret *= a / gcd(a, b);
		ret *= b / gcd(a, b);
		cout << ret << endl;
	}
}
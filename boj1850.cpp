/*유클리드 알고리즘을 활용한다.
최대공약수를 구하고, 그 길이만큼 1을 출력해준다*/
#include<iostream>
#include<algorithm>

using namespace std;

int gcd(long long a, long long b) {
	if (a%b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
int main() {
	long long a, b, ret;
	ret = 0;
	cin >> a >> b;
	ret = gcd(a, b);
	for (int i = 1; i <= ret; i++) {
		cout << 1;
	}
	cout << endl;
	return 0;
}
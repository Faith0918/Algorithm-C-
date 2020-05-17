#include<iostream>
#include<vector>
#include<string>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, n;
	long long x, a, b;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<long long> v;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			v.push_back(x);
		}
		
		long long sum = 0;
		if (v.size() == 1) {
			cout << v[0] << "\n";
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				a = v[i];
				for (int j = i + 1; j < v.size(); j++) {
					b = v[j];
					sum += gcd(a, b);
				}
			}
			cout << sum << "\n";
		}
		
	}
}
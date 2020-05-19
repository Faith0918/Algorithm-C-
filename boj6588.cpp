#include<iostream>
#include<math.h>
#include<vector>
using namespace std;



int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int MAX = 1000000;
	int* prime = new int[MAX+1];
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		prime[i] = 1;
		
	}
	for (int i = 2; i <= MAX; i++) {
		if (prime[i]==1) {
			int j = i * i;
			while (j <= MAX) {
				prime[j] = 0;
				j += i;
			}
		}
		
	}
	while (1) {
		int n, a, b, a_t, b_t;
		a = 0;
		b = 0;
		int sub = -1;
		vector<int> v;
		cin >> n;
		if (n == 0) break;
		else {
			for (int i = 3; i <= n; i += 2) {
				if (prime[i] == 1) {
					v.push_back(i);
				}
			}
			for (int i = 0; i < v.size(); i++) {
					a_t = v[i];
					for (int j = v.size()-1; j >=i; j--) {
							b_t = v[j];
							if (a_t+b_t==n && b_t - a_t > sub) {
								a = a_t;
								b = b_t;
								sub = b - a;
								break;
							}
					}
					if (sub != -1) {
						break;
					}
			}
			if (sub == -1) {
				cout << "Goldbach's conjecture is wrong.\n";
				break;
			}
			cout << n << " = " << a << " + " << b;
		}
	}
}
#include<vector>
#include<iostream>

using namespace std;

const int MAX = 10000001;
int p[MAX];
vector<int> prime;

void find_prime() {
	p[0] = p[1] = -1;
	for(int i = 2; i < MAX; i++) {
		p[i] = i;
	}

	for (int i = 2; i * i < MAX; i++) {
		for (int j = i * i; j < MAX; j+=i) {
			if (p[j] == j) {
				p[j] = i;
			}
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (p[i] == i)
			prime.push_back(i);
	}
}
int main() {
	find_prime();
	int n;
	cin >> n;
	while (n > 1) {
		for (int i = 0; i < prime.size(); i++) {
			if (n % prime[i] == 0) {
				n /= prime[i];
				cout << prime[i]<<"\n";
				break;
			}
		}
	}
}

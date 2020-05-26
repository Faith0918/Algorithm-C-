#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k, maxx;

int main() {
	cin >> n >> m >> k;
	maxx = 0;
	for (int i = 0; i <= k; i++) {
		if (n >= i && m >= k - i) {
			int t = min((n-i) / 2, (m-k+i));
			maxx = max(maxx, t);
			//cout<<"max : "<<maxx<<" n ; "<<
		}
	}
	cout << maxx;
}
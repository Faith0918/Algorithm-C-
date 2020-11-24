#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());
	int i = 0;
	int cnt = 0;
	while (i < N) {
		int biggest = v[i];
		i += v[i];
		if (i > N) {
			break;
		}
		else {
			cnt++;
		}
	}
	cout << cnt;

}
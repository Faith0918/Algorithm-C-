//매번 최대/최소를 갱신해야하는 경우 priority queue  자료구조가 유리하다.

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int n;
	priority_queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(-a);
	}
	int ans = 0;
	int cmp_cnt = 0;
	while (!q.empty()) {
		if (cmp_cnt == n - 1) break;
		int Num1 = -q.top(); q.pop();
		int Num2 = -q.top(); q.pop();
		ans = ans + (Num1 + Num2);
		q.push(-(Num1 + Num2));
		cmp_cnt++;
	}
	cout << ans;
	
}
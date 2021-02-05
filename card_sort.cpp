//�Ź� �ִ�/�ּҸ� �����ؾ��ϴ� ��� priority queue  �ڷᱸ���� �����ϴ�.

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
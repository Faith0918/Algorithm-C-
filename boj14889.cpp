#include<iostream>

using namespace std;

int n;
int arr[21][21];
int visited[21] = {};
int ans;

void combi(int cnt, int cur) {
	if (cnt == n / 2) {
		cout << "count meet" << endl;
		int a = 0, b = 0, candi = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (visited[i] == 1 && visited[j] == 1) {
					cout << "team1 : " << i << ", "<<j<<endl;
					a = a + arr[i][j] + arr[j][i];
				}
				else if (visited[i] == 0 && visited[j] == 0) {
					b = b + arr[i][j] + arr[j][i];
					cout << "team2 : "<< i << ", " << j << endl;
				}
			}
		}
		if (b > a) {
			candi = b - a;
		}
		else {
			candi = a - b;
		}
		if (candi < ans) {
			ans = candi;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 && i > cur) {
				visited[i] = 1;
				cout << "i : " << i << endl;
				combi(cnt+1, i);
				visited[i] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	ans = (int)1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	combi(0, 0);
	cout << ans;
}
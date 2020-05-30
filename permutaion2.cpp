#include<iostream>

using namespace std;

const int MAX = 100;
int n, m;
int arr[MAX] = { 0 };
bool visited[MAX] = { false };

void dfs(int cnt) {
	if (cnt == m) {
		//print
		for (int i = 0; i < m; i++) {
			cout << (char)(arr[i] + 'a');
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				arr[cnt] = i;
				dfs(cnt + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
}
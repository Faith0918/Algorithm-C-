#include<iostream>

using namespace std;

const int MAX = 100;
int n;
int arr[MAX];
bool visited[MAX] = { false };
void dfs(int i) {
	if (i > n) {
		for (int j = 1; j <= n; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
	}
	else {
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				visited[j] = true;
				arr[i] = j;
				dfs(i+1);
				visited[j] = false;
				arr[i] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	dfs(1);
	return 0;
}
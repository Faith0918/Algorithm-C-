#include<iostream>

using namespace std;

int tc, n, index;
int arr[1001];

void dfs(int idx, bool* visited) {
	if (arr[idx] == index) {
		return;
	}
	else {
		
			visited[arr[idx]] = true;
			dfs(arr[idx], visited);

		
	}
	
}



int main() {
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
		}
		bool visited[1001] = {false,};
		for (int j = 1; j <= n; j++) {
			if (visited[j] == false) {
				index = j;
				visited[j] = true;
				cnt++;
				dfs(j, visited);
			}
		}
		cout << cnt<<"\n";
	}
}
//Needs to be solved in BFS if not, it will take more time than given time.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, X, K;
vector<vector<int>> v;
vector<bool> visited;
vector<int> answer;
void dfs(int node, int cnt) {
	if (cnt == K) {
		return;
	}
	else {
		for (int i = 0; i < v[node].size(); i++) {
			int next_node = v[node][i];
			if (!visited[next_node]) {
				visited[next_node] = true;
				if (answer[next_node] > cnt+1) {
					answer[next_node] = cnt+1;
					dfs(next_node, cnt + 1);
					visited[next_node] = false;
				}
				
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K >> X;
	vector<vector<int>> v_(N);
	vector<bool> visited_(N);
	vector<int> ans(N, (int)1e9);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v_[a - 1].push_back(b-1);

	}
	v = v_;
	visited = visited_;
	answer = ans;
	visited[X-1] = true;
	answer[X - 1] = 0;
	dfs(X-1, 0);
	
	bool check = false;
	for (int i = 0; i < answer.size(); i++) {
		//cout << "answer[" << i + 1 << "] = " << answer[i]<<"\n";
		if (answer[i] == K) {
			check = true;
			cout << i+1 << "\n";
		}
		
	}
	if (!check) {
		cout << -1;
	}
	return 0;
}
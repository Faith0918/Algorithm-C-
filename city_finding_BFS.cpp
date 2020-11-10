#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
//Problem content
//print every city; that's minimum distance equals to K from city X

int N, M, K, X;

int main() {
	cin >> N >> M >> K >> X;
	vector<vector<int>> v(N);
	vector<bool> visited(N);
	vector<int> ans;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a-1].push_back(b-1);

	}
	queue<pair<int, int> > q;
	q.push(make_pair(X-1,0));
	visited[X-1] = true;
	bool flag = false;
	while (!q.empty()) {
		//cout << "while\n";
		pair<int,int> cur_node = q.front();
		int cur_city = cur_node.first;
		int cur_dist = cur_node.second;
		//cout << cur_city << " ; " << cur_dist << "\n";
		visited[cur_city] = true;
		for (int i = 0; i < v[cur_city].size(); i++) {
			int next_city = v[cur_city][i];
			if (visited[next_city] == false ) {
				if (cur_dist == K - 1) {
					ans.push_back(next_city+1);
				}
				visited[next_city] = true;
				q.push(make_pair(next_city, cur_dist + 1));
			}
		}
		q.pop();
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
		cout << -1;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

}
// Solving process
// 1. get the input map
//		0:blank	1:wall	2:virus
// 2. Choose 3 blank spaces to place the wall.(DFS)
// 3. Save the temporary map with the 3 additional walls
// 4. Spread virus all over to the temporary map.(BFS)
// 5. Compare the number of safe places with the answer candidate.
// 6. Update the answer if the number is bigger than the answer candidate.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> tmp_map;
vector<vector<int>> visited;
queue<pair<int,int>> virus;
int answer = 0;
int N, M;
int BFS() {
	int safe = 0;
	queue<pair<int, int>> q = virus;
	int dr[4] = {0,1,0,-1};
	int dc[4] = {1,0,-1,0};
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		int cur_r = node.first;
		int cur_c = node.second;
		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];
			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) {
				if (tmp_map[next_r][next_c] == 0) {
					tmp_map[next_r][next_c] = 2;
					q.push(make_pair(next_r, next_c));
				}
			}
		}
		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp_map[i][j] == 0) {
				safe++;
			}
		}
	}
	return safe;
}
void DFS(int cnt) {
	if (cnt == 3) {
		tmp_map = map;
		int candi = BFS();
		if (candi > answer) {
			answer = candi;
		}
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0 && !visited[i][j]) {
					visited[i][j] = true;
					map[i][j] = 1;
					DFS(cnt + 1);
					visited[i][j] = false;
					map[i][j] = 0;
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> tmp_m;
		vector<int> tmp_v;
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			if (a == 2) {
				virus.push(make_pair(i, j));
			}
			tmp_m.push_back(a);
			tmp_v.push_back(false);
		}
		map.push_back(tmp_m);
		visited.push_back(tmp_v);
	}
	DFS(0);
	cout << answer;
}
#include<iostream>
#include<vector>

using namespace std;
int n, l, R;
vector<vector<int>> map;
vector<vector<bool>> visited;
bool isMoving = true;
int answer = 0;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int cnt = 1;
int sum = 0;
vector<pair<int, int>> open;
void initialize_visited() {
	vector<vector<bool>> tmp;
	for (int i = 0; i < n; i++) {
		vector<bool> v;
		for (int j = 0; j < n; j++) {
			v.push_back(false);
		}
		tmp.push_back(v);
	}
	visited = tmp;
}
void dfs(int r, int c) {
	if (visited[r][c]) {
		return;
	}
	
	else {
		visited[r][c] = true;
		for (int i = 0; i < 4; i++) {
			int next_r = r + dr[i];
			int next_c = c + dc[i];
			if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) {
				
				if (!visited[next_r][next_c] && abs(map[r][c] - map[next_r][next_c]) >= l && abs(map[r][c] - map[next_r][next_c]) <= R) {
					
					cnt = cnt + 1;
					sum += map[next_r][next_c];
					open.push_back(make_pair(next_r, next_c));
					dfs(next_r, next_c);
				}
			}
		}
	}
}

int main() {
	cin >> n >> l >> R;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		map.push_back(v);
	}
	while (isMoving) {
		initialize_visited();
		isMoving = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					open.clear();
					open.push_back(make_pair(i, j));
					cnt = 1;
					sum = map[i][j];
					dfs(i, j);
					if (cnt > 1) {
						int population = sum / cnt;
						for (int k = 0; k < open.size(); k++) {
							pair<int, int> node = open[k];
							map[node.first][node.second] = population;
						}
						isMoving = true;
					}
					
				}
				
			}
		}
		if (isMoving) {
			answer++;
		}
	}
	cout << answer;

}
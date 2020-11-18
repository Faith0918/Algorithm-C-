/*
6
X X X X X X
S S S S S S
X X X X X X
X X X X X X
X X X X X X
T T X X X X
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<vector<int>> map;//0:blank, 1:student, 2:teacher, -1:wall
vector<pair<int, int>> teacher;
bool isPossible = false;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
int students = 0;

void watch_line(int r, int c, int dir, vector<vector<int>>& tmp, bool(&visited)[7][7]) {

	queue<pair<int, int>> q;

	q.push(make_pair(r, c));

	while (!q.empty()) {
		pair<int, int> cur_node = q.front();
		q.pop();
		int cur_r = cur_node.first;
		int cur_c = cur_node.second;
		int next_r = cur_r + dr[dir];
		int next_c = cur_c + dc[dir];
		if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) {
			if (tmp[next_r][next_c] >= 0) {
				tmp[next_r][next_c] = 2;
				q.push(make_pair(next_r, next_c));
			}

		}


	}

}

bool isAvoidable() {
	vector<vector<int>> tmp = map;
	queue<pair<int, int>> q;
	bool visited[7][7] = { false };
	for (int i = 0; i < teacher.size(); i++) {
		pair<int, int> cur_node = teacher[i];
		int cur_r = cur_node.first;
		int cur_c = cur_node.second;
		for (int j = 0; j < 4; j++) {
			watch_line(cur_r, cur_c, j, tmp, visited);
		}

	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j] == 1) {
				cnt++;
			}
		}
	}

	if (cnt == students) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int i_idx, int j_idx, int cnt) {
	if (cnt == 3) {

		if (isAvoidable()) {
			isPossible = true;
		}
		return;
	}
	else {
		if (!isPossible) {
			for (int j = j_idx; j < n; j++) {
				if (map[i_idx][j] == 0) {
					map[i_idx][j] = -1;

					dfs(i_idx, j, cnt + 1);

					map[i_idx][j] = 0;
				}
			}
			for (int i = i_idx + 1; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] == 0) {
						map[i][j] = -1;

						dfs(i, j, cnt + 1);

						map[i][j] = 0;
					}
				}
			}
		}

	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			if (a == 'X') {
				v.push_back(0);
			}
			else if (a == 'S') {
				students++;
				v.push_back(1);
			}
			else if (a == 'T') {
				teacher.push_back(make_pair(i, j));
				v.push_back(2);
			}
		}
		map.push_back(v);
	}
	//cout << "students : " << students << "\n";
	dfs(0, 0, 0);
	if (isPossible) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}
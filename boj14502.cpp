#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int> > v;
int ans = 0;
int n, m;
int arr[9][9];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int spread(int candi[][9]) {
	queue<pair<int, int> > q;
	bool visited[9][9] = { false };
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		visited[v[i].first][v[i].second] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (candi[i][j] == 0) {
				sum++;
			}
		}
	}
	
	while (!q.empty()) {
		pair<int, int> a = q.front();
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int next_r = a.first + dr[k];
			int next_c = a.second + dc[k];
			if (next_r > 0 && next_r <= n && next_c > 0 && next_c <= m && candi[next_r][next_c] == 0&&visited[next_r][next_c] == false) {
				candi[next_r][next_c] = 2;
				q.push(make_pair(next_r, next_c));
				sum--;
			}
		}
	}
	
	
	return sum;
}

void dfs(int cnt, int cur_r, int cur_c) {
	if (cnt == 3) {
		
		int candi[9][9] = {};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				candi[i][j] = arr[i][j];
			}
		}
		int ca = spread(candi);
		
		if (ca > ans) {
			/*for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					cout << candi[i][j] << "\t";
				}
				cout << endl;
			}
			cout << "candi : " << ca << endl;*/
			ans = ca;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1 ; j <= m; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					dfs(cnt + 1, i, j);
					arr[i][j] = 0;
				}
				
			}
		}
	}	
	
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j ++ ) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	dfs(0, 1, 1);
	
	cout << ans;
}

#include<iostream>

using namespace std;

int n, m;
int ans = 0;
int arr[501][501];
bool visited[501][501] = {false};
int dr[6] = { 0,0,1,-1,1,-1 };
int dc[6] = { 1,-1,0,0 ,1,-1};
bool shared(int next_r, int next_c) {
	for (int i = 0; i < 4; i++) {
		if (visited[next_r + dr[i]][next_c + dc[i]]) {
			return true;
		}
	}
	return false;
}
void dfs(int cnt, int cur_i, int cur_j, int candi) {
	if (cnt == 4) {
		if (candi > ans) {
			//cout << "cnt = 4 candi>ans" << endl;
			/*for (int r = 1; r <= n; r++) {
				for (int c = 1; c <= m; c++) {
					if (visited[r][c] == true) {
						cout << "r : " << r << " c : " << c << endl;
					}
					
				}
			}*/
			//cout << "candi : " << candi << endl;
			ans = candi;
			return;
		}
		
		
	}
	else {
		if (cnt >= 2) {
			for (int k = 0; k < 6; k++) {
				int next_r = cur_i + dr[k];
				int next_c = cur_j + dc[k];

				if (next_r <= n && next_r > 0 && next_c <= m && next_c > 0 && visited[next_r][next_c] == false&&shared(next_r,next_c) ){
					visited[next_r][next_c] = true;
					dfs(cnt + 1, next_r, next_c, candi + arr[next_r][next_c]);
					visited[next_r][next_c] = false;
				}
			}
		}
		for (int k = 0; k < 4; k++) {
			int next_r = cur_i + dr[k];
			int next_c = cur_j + dc[k];
			
			if (next_r <= n && next_r > 0 && next_c <= m && next_c > 0&&visited[next_r][next_c] == false ) {
				visited[next_r][next_c] = true;
				dfs(cnt + 1, next_r, next_c, candi + arr[next_r][next_c]);
				visited[next_r][next_c] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dfs(0, i, j, 0);

		}
	}
	cout << ans;
}
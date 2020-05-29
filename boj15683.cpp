#include<iostream>
#include<vector>

using namespace std;

struct cctv {
public:
	int r, c, d, type;
};

int n, m;
int minn = (int)1e9;
int arr[9][9];
vector<cctv> CCTV;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
void cctv_on(int idx, int dir) {
	int next_r = CCTV[idx].r;
	int next_c = CCTV[idx].c;
	while (1) {
		next_r += dr[dir];
		next_c += dc[dir];
		if (next_r > 0 && next_r <= n && next_c > 0 && next_c <= m && arr[next_r][next_c] != 6) {
			if (arr[next_r][next_c] <= 0) {
				arr[next_r][next_c]--;
			}
			
		}
		else {
			break;
		}
	}
}

void cctv_off(int idx, int dir) {
	int next_r = CCTV[idx].r;
	int next_c = CCTV[idx].c;
	while (1) {
		next_r += dr[dir];
		next_c += dc[dir];
		if (next_r > 0 && next_r <= n && next_c > 0 && next_c <= m && arr[next_r][next_c] != 6) {
			if (arr[next_r][next_c] < 0) {
				arr[next_r][next_c] ++ ;
			}

		}
		else {
			break;
		}
	}
}

void dfs(int cnt) {
	//cout << "dfs " << cnt << endl;
	if (cnt == CCTV.size()) {
		int candi = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 0) {
					candi++;
				}
			}
		}
		if (candi < minn) {
			minn = candi;
			////cout << "min : " << minn << endl;
			//for (int r = 1; r <= n; r++) {
			//	for (int c = 1; c <= m; c++) {
			//		//cout << arr[r][c] << "\t";
			//	}
			//	cout << "\n";
			//}
			
		}
		return;
	}
	else {
		switch (CCTV[cnt].type)
		{
		case 1:
			for (int k = 0; k < 4; k++) {
				cctv_on(cnt,k);
				dfs(cnt + 1);
				cctv_off(cnt,k);
			}
			break;			
		case 2:
			for (int k = 0; k < 2; k++) {
				cctv_on(cnt,k);
				cctv_on(cnt, k+2);
				dfs(cnt + 1);
				cctv_off(cnt,k);
				cctv_off(cnt, k+2);
			}
			break;
		case 3:
			for (int k = 0; k < 4; k++) {
				cctv_on(cnt,k);
				cctv_on(cnt, (k+1)%4);
				dfs(cnt + 1);
				cctv_off(cnt,k);
				cctv_off(cnt, (k + 1) % 4);
			}
			break;
		case 4:
			for (int k = 0; k < 4; k++) {
				cctv_on(cnt,k);
				cctv_on(cnt, (k+1)%4);
				cctv_on(cnt, (k + 2) % 4);
				dfs(cnt + 1);
				cctv_off(cnt,k);
				cctv_off(cnt, (k + 1) % 4);
				cctv_off(cnt, (k + 2) % 4);
			}
			break;
		default:
			cctv_on(cnt, 0);
			cctv_on(cnt, 1);
			cctv_on(cnt, 2);
			cctv_on(cnt, 3);
			dfs(cnt + 1);
			cctv_off(cnt, 0);
			cctv_off(cnt, 1);
			cctv_off(cnt, 2);
			cctv_off(cnt, 3);
			break;
		}
		

	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6) {
				cctv a;
				a.type = arr[i][j];
				a.r = i;
				a.c = j;
				a.d = 0;
				CCTV.push_back(a);
			}
		}
	}
	dfs(0);
	cout << minn;
}
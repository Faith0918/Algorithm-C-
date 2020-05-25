#include<iostream>
using namespace std;
int x, y, d1, d2;
int n;
int a[21][21] = {};
int ans = (int)1e9;
int b[21][21] = {};

void clearArray() {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			b[i][j] = 0;
		}
	}
}

void dfs(int cnt, int x, int y, int d1, int d2) {
	if (cnt == 4) {
		int maxx = 0;
		int minn = (int)1e9;
		/*cout << "x : " << x;
		cout << " y : " << y;
		cout << " d1 : " << d1;
		cout << " d2 : " << d2 << "\n";*/
		clearArray();
		//border
		for (int r = x, c = y; r <= x + d1; r++, c--) {//1
			b[r][c] = 5;
		}
		for (int r = x, c = y; r <= x + d2; r++,c++) {//2
			b[r][c] = 5;
		}
		for (int r = x + d1, c = y - d1; r <= x + d1 + d2; r++, c++) {//3
			b[r][c] = 5;
		}
		for (int r = x + d2, c = y + d2; r <= x + d2 + d1; r++, c--) {//4
			b[r][c] = 5;
		}
		//inside
		for (int r = x + 1; r < x + d1 + d2; r++) {
			bool flag = false;
			for (int c = 0; c <= n; c++) {
				if (b[r][c] == 5) {
					flag = !flag;
				}
				if (flag && b[r][c] == 0) {
					b[r][c] = 5;
				}
			}
		}
		//No 1
		for (int r = 1; r < x + d1; r++) {
			for (int c = 1; c <= y; c++) {
				if(b[r][c]==0)	b[r][c] = 1;
			}
		}
		//No 2
		for (int r = 1; r <= x + d2; r++) {
			for (int c = y + 1; c <= n; c++) {
				if (b[r][c] == 0) b[r][c] = 2;
			}
		}
		//No 3
		for (int r = x + d1; r <= n; r++) {
			for (int c = 1; c < y - d1 + d2;c++) {
				if (b[r][c] == 0) b[r][c] = 3;
			}
		}
		//No 4
		for (int r = x + d2 + 1; r <= n; r++) {
			for (int c = y - d1 + d2; c <= n; c++) {
				if (b[r][c] == 0) b[r][c] = 4;
			}
		}
		//for map, find maxx and minn
		int pop[6] = { 0 };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int num = b[i][j];
				pop[num] += a[i][j];
			}
		}
		for (int i = 1; i <= 5; i++) {
			if (pop[i] > maxx) {
				maxx = pop[i];
			}
			if (pop[i] < minn) {
				minn = pop[i];
			}
		}
		if (ans > maxx - minn) ans = maxx - minn;
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << b[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "maxx : " << maxx << endl;
		cout << "minn : " << minn << endl;*/
	}
	else {
		if (cnt == 0) {//d1 select
			for (int i = 1; i <= n; i++) {
				dfs(cnt + 1, x, y, i, d2);
			}
		}
		if (cnt == 1) {//d2 select
			for (int i = 1; i <= n - d1 - x; i++) {
				dfs(cnt + 1, x, y, d1, i);
			}
		}
		if (cnt == 2) {//x select
			for (int i = 1; i <= n - d1 - d2; i++) {
				dfs(cnt + 1, i, y, d1, d2);
			}
		}
		if (cnt == 3) {//y select
			for (int i = 1 + d1; i<=n - d2; i++) {
				dfs(cnt + 1, x, i, d1, d2);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, 0, 0, 0, 0);
	cout << ans;

}
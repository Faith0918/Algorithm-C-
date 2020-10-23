#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		long long ans = 0;
		cin >> N;
		vector<vector<int> > v(N + 1);
		for (int r = 1; r <= N; r++) {
			vector<int> tmp(N + 1);
			for (int c = 1; c <= N; c++) {
				cin >> tmp[c];
			}
			v[r] = tmp;
		}

		for (int r = 1; r <= N; r++) {
			long long candi = 0;
			int t_r = r;
			for (int c = 1; c <= N - r + 1; c++) {
				candi += (long long)v[t_r][c];
				t_r++;
			}
			if (candi > ans) ans = candi;

		}
		for (int c = 1; c <= N; c++) {
			long long candi = 0;
			int t_c = c;
			for (int r = 1; r <= N - c + 1; r++) {
				candi += (long long)v[r][t_c];
				t_c++;
			}
			if (candi > ans) ans = candi;

		}
		cout << "Case #" << t << ": " << ans << "\n";
	}


}
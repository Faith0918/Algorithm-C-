#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {

	int T;
	int W, N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> W >> N;
		vector <int> wheel(W + 1);
		long long ans = (long long)1e18;
		for (int i = 1; i <= W; i++) {
			cin >> wheel[i];
		}

		for (int i = 1; i <= N; i++) {
			long long candi = 0;
			for (int j = 1; j <= W; j++) {
				if (candi >= ans) {
					break;
				}
				int X = wheel[j];
				int Y = i;
				if (Y > X) {
					candi += (long long)min(Y - X, N - Y + X);
				}
				else if (Y < X) {
					candi += (long long)min(X - Y, Y + N - X);
				}
			}
			if (candi < ans) {
				ans = candi;
			}
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
}
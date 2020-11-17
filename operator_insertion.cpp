// 1. save number array and operator array
// 2. use dfs algorithm to try every possible permutation of operator.


#include<vector>
#include<iostream>

using namespace std;

vector<int> number;
vector<int> op;
int maxx = -(int)1e9;
int minn = (int)1e9;

void dfs(int cnt, int candi) {
	if (cnt == number.size() - 1) {
		if (candi > maxx) {
			maxx = candi;
		}
		if (candi < minn) {
			minn = candi;
		}
		return;
	}
	else {
		if (op[0] > 0) {
			//+
			op[0]--;
			dfs(cnt + 1, candi + number[cnt + 1]);
			op[0]++;
		}
		if (op[1] > 0) {
			//-
			op[1]--;
			dfs(cnt + 1, candi - number[cnt + 1]);
			op[1]++;
		}
		if (op[2] > 0) {
			op[2]--;
			dfs(cnt + 1, candi * number[cnt + 1]);
			op[2]++;
			//*
		}
		if (op[3] > 0) {
			///
			op[3]--;
			dfs(cnt + 1, candi / number[cnt + 1]);
			op[3]++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		number.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int o;
		cin >> o;
		op.push_back(o);
	}
	dfs(0, number[0]);
	cout << maxx << "\n";
	cout << minn << "\n";

}
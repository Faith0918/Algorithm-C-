//Test Case
/*
5 6
101010
111111
000001
111111
111111
*/
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<utility>

using namespace std;

int main() {
	int N,M;
	vector<vector<int>> map;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		string s;
		//TODO : string input needs to be done.
		getline(cin,s);
		for (int j = 0; j < M; j++) {
			v.push_back(s[j]-'0');
		}
		map.push_back(v);
	}
	//Doingbin is in cell 0,0
	vector<int> db(3);
	db[0] = 0;
	db[1] = 0;
	db[2] = 1;
	queue<vector<int>> q;
	q.push(db);
	while (!q.empty()) {
		vector<int> cur_l = q.front();
		int cur_r = cur_l[0];
		int cur_c = cur_l[1];
		int count = cur_l[2];
		int dir_r[4] = {1,0,-1,0};
		int dir_c[4] = {0,1,0,-1};
		if (cur_r == N - 1 && cur_c == M - 1) {

		}
		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dir_r[i];
			int next_c = cur_c + dir_c[i];
			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) {
				if (map[next_r][next_c] == 1) {
					vector<int> a;
					a.push_back(next_r);
					a.push_back(next_c);
					a.push_back(count + 1);
					q.push(a);
				}
			}
		}
	}
}
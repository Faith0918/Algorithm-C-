//vector iterator, pointer, reference 개념 다시한번 정리해야함!!!!


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class horse {
public:
	int r, c, d;
};

int n,k,turn;
horse horses[11];
vector<int> info[13][13];
int map[13][13];
int change[4] = {1,0,3,2};
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
int move(int i) {
	horse& h = horses[i];
	int next_r = h.r + dr[h.d];
	int next_c = h.c + dc[h.d];
	if (next_r <= 0 || next_r > n || next_c <= 0 || next_c > n || map[next_r][next_c] == 2) {
		h.d = change[h.d];
		next_r = h.r + dr[h.d];
		next_c = h.c + dc[h.d];
		if (next_r <= 0 || next_r > n || next_c <= 0 || next_c > n || map[next_r][next_c] == 2) {
			return 0;
		}
	}

	vector<int>& cur = info[h.r][h.c];
	vector<int>& next = info[next_r][next_c];
	auto s = find(cur.begin(), cur.end(), i);

	if (map[next_r][next_c] == 1) {
		reverse(s, cur.end());
	}

	for (auto it = s; it != cur.end(); it++) {
		horses[*it].r = next_r;
		horses[*it].c = next_c;
		next.push_back(*it);
		
	}
	cur.erase(s, cur.end());
	return next.size();
}

int main() {
	cin >> n>>k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		horse h;
		cin >> h.r >> h.c >> h.d;
		h.d--;
		horses[i] = h;
		info[h.r][h.c].push_back(i);
		if (info[h.r][h.c].size() >= 4) {
			cout << -1;
			return 0;
		}
	}
	for (turn = 1; turn <= 1000; turn++) {
		for (int i = 1; i <= k; i++) {
			;
			if (move(i) >= 4) {
				cout << turn;
				return 0;
			}
		}
	}

	cout << -1;
}
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class place {
public:
	int r;
	int c;
};

vector<place> house;
vector<place> store;
int n, m;
int map[51][51] = {};
int visited[13] = {};
int s[13] = {};
int minn = (int)1e9;
int dist[13][100] = {};

void calculate_distance() {
	for (int i = 0; i < store.size(); i++) {
		for (int j = 0; j < house.size(); j++) {
			dist[i][j] = abs(store[i].r - house[j].r) + abs(store[i].c - house[j].c);
			
		}
	}
}

int city_chicken_distance() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int mm = 1000;
		for (int j = 0; j < m; j++) {
			int c_idx = s[j];
			if (dist[c_idx][i] < mm) {
				mm = dist[c_idx][i];
			}
		}
		sum += mm;
	}
	return sum;
}

void dfs(int cnt, int idx) {
	if (cnt == m) {
		int candi = city_chicken_distance();
		if (candi < minn) {
			minn = candi;
		}
		return;
	}
	else {
		for (int i = idx; i < store.size(); i++) {
			s[cnt] = i;
			dfs(cnt + 1, i + 1);
			s[cnt] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				//house
				place p;
				p.r = i;
				p.c = j;
				house.push_back(p);
			}
			else if (map[i][j] == 2) {
				//store
				place p;
				p.r = i;
				p.c = j;
				store.push_back(p);
			}
		}
	}
	calculate_distance();
	dfs(0, 0);
	cout << minn;
}
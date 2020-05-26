#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

class shark {
public:
	int r, c, size, t, cnt;
};
int n;
int a[21][21] = {};
bool visited[21][21] = {};
shark s;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int min_time = (int)1e9;
pair<int, int> min_point;

void clearQueue(queue<tuple<int, int, int> > &q) {
	queue<tuple<int, int, int> > empty_q;
	swap(q, empty_q);
}
void clearVisited() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = false;
		}
	}
}
void bfs() {
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(s.r, s.c, 0));
	while (!q.empty()) {
		tuple<int, int, int> t = q.front();
		q.pop();
		int cur_r = get<0>(t);
		int cur_c = get<1>(t);
		int cur_t = get<2>(t);
		if (a[cur_r][cur_c] < s.size && a[cur_r][cur_c] >0) {
			//edible
			if (min_time == (int)1e9) {
				min_time = cur_t;
				min_point = make_pair(cur_r, cur_c);
			}
			if (cur_t == min_time) {
				if (min_point.first > cur_r) {
					min_point = make_pair(cur_r, cur_c);
				}
				else if (min_point.first == cur_r) {
					if (min_point.second > cur_c) {
						min_point = make_pair(cur_r, cur_c);
					}
				}
			}
			
			
		}
		if (cur_t > min_time||cur_t==min_time &&q.empty()) {
			a[min_point.first][min_point.second] = 0;
			s.cnt++;
			s.r = min_point.first;
			s.c = min_point.second;
			s.t += min_time;
			//cout << "cur_r : " << s.r << " cur_c : " << s.c << " s.t : " << s.t << endl;
			cur_t = 0;
			cur_r = s.r;
			cur_c = s.c;
			clearQueue(q);
			clearVisited();
			min_time = (int)1e9;
			if (s.cnt == s.size) {
				s.size++;
				s.cnt = 0;
			}
		}
		for (int k = 0; k < 4; k++) {
			int next_r = cur_r + dr[k];
			int next_c = cur_c + dc[k];
			int next_t = cur_t + 1;
			//cout << "next_r : " << next_r << " next_c : " << next_c << " cur_t : " << cur_t << endl;
			if (next_r > 0 && next_r <= n && next_c > 0 && next_c <= n && a[next_r][next_c] <= s.size&&visited[next_r][next_c] == false) {
				//cout << "if" << endl;
				q.push(make_tuple(next_r, next_c, next_t));
				visited[next_r][next_c] = true;
			}
			
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				s.r = i;
				s.c = j;
				s.size = 2;
				s.t = 0;
				s.cnt = 0;
				a[i][j] = 0;
			}
		}
	}
	bfs();
	cout << s.t;
}
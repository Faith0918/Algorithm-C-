/*Test case
1 1
0
0 1 1

1 1
1
0 1 1


*/
// 1) Get the input map and push points with virus presents.
// 2) BFS : Spread virus for S seconds in ascending order.
// 3) Get the value of map[X-1][Y-1];

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		if (a[2] == b[2]) {
			return a[3] > b[3];
		}
		else {
			return a[2] > b[2];
		}
	}
};

int main() {
	int N, K, S, X, Y;
	vector<vector<int>> map;
	vector<vector<int>> time_map;
	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
	//TODO : Queue sorting needs to be done
	//Method Needs to be tried : primary_queue compare function
	cin >> N >> K;
	//initialize map
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			int a;
			vector<int> point;
			cin >> a;
			if (a > 0) {
				point.push_back(i);
				point.push_back(j);
				point.push_back(0);
				point.push_back(a);
				q.push(point);
			}
			v.push_back(a);
			
		}
		map.push_back(v);
	}
	//initialize time map
	for (int i = 0; i < N; i++) {
		vector<int> v_;
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0) {
				v_.push_back(0);
			}
			else {
				v_.push_back((int)1e9);
			}
		}
		time_map.push_back(v_);
	}
	// BFS
	while (!q.empty()) {
		vector<int> node = q.top();
		q.pop();
		
		int cur_y = node[0];
		int cur_x = node[1];
		int cur_t = node[2];
		int cur_n = node[3];
		//cout << cur_n << "\n";
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			int next_t = cur_t + 1;
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N ) {
				if (map[next_y][next_x] == 0) {
					map[next_y][next_x] = map[cur_y][cur_x];
					time_map[next_y][next_x] = next_t;
					vector<int> next_node(4);
					next_node[0] = next_y;
					next_node[1] = next_x;
					next_node[2] = next_t;
					next_node[3] = cur_n;
					q.push(next_node);
				}
			}
			
		}
	}
	cin >> S >> X >> Y;
	//cout << "map\n";
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << map[i][j] << "\t";
	//	}
	//	cout << "\n";
	//}
	//cout << "time map\n";
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << time_map[i][j] << "\t";
	//	}
	//	cout << "\n";
	//}
	if (time_map[X - 1][Y - 1] <= S) {
		cout << map[X - 1][Y - 1]<<"\n";
	}
	else {
		cout << 0<<"\n";
	}
	
}
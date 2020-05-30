//최단경로찾는 알고리즘
//확정되지 않은 노드 중 최소값을 갖는 노드를 찾는다.
//인접노드로 펼쳐나간다
//start 8:53 end 9:04
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxx = 100;
int n, m, start, finish;
vector<int> graph[maxx];
vector<int> cost[maxx];
int table[maxx] = {};
bool visited[maxx] = {false};

int main() {
	cin >> n >> m >> start >> finish;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(b);
		graph[b].push_back(a);
		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	for (int i = 0; i < n; i++) {
		table[i] = (int)1e9;
	}
	table[start] = 0;
	for (int i = 0; i < n; i++) {
		int min_v = (int)1e9;
		int min_i = 0;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && min_v > table[j]) {
				min_v = table[j];
				min_i = j;
			}
		}
		visited[min_i] = true;
		for (int j = 0; j < graph[min_i].size(); j++) {
			int node2 = graph[min_i][j];
			int cost2 = cost[min_i][j];
			if (table[node2] > table[min_i] + cost2) {
				table[node2] = table[min_i] + cost2;
			}
		}
	}
	cout << table[finish];
}
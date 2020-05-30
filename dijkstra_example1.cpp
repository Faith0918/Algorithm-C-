//(1)최솟값을 구한다. 단, 지금까지 최단거리를 확정하지 않았던 정점에 대해서.
//(2)그 최솟값을 갖는 노드부터 뻗어나간다.

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int v;
int e;
int start;
int finish;
const int MAX = 100;
vector<int > graph[MAX];
vector<int> cost[MAX];
int table[MAX] = {0,};
bool visited[MAX] = {false,};

int main() {
	cin >> v >> e >> start >> finish;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(b);
		graph[b].push_back(a);
		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	for (int i = 0; i < v; i++) {
		table[i] = (int)1e9;
	}
	table[start] = 0;
	for (int i = 0; i < v; i++) {
		
		//v번 반복
		int minn = (int)1e9;
		int min_idx = 0;
		for (int j = 0; j < v; j++) {
			//visit하지 않은 최단 노드를 찾는다.
			if (!visited[j] && minn > table[j]) {
				minn = table[j];
				min_idx = j;
			}
			
		}
		visited[min_idx] = true;
		cout << "min idx : " << min_idx << endl;
		for (int j = 0; j < graph[min_idx].size(); j++) {
			int Node2 = graph[min_idx][j];
			cout << "next node idx : " << Node2 << endl;
			int Cost2 = cost[min_idx][j];
			cout << "next cost : " << Cost2 << endl;
			//minIdx --cost2---- node2
			if (table[Node2] > Cost2 + table[min_idx]) {
				table[Node2] = Cost2 + table[min_idx];
			}
		}
	}
	cout << finish << endl;
	cout << table[finish];
}
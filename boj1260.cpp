#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> > v;
queue<int> q;
int visited[1001] = {};
int n, m, f;
void dfs(int p) {
	cout << p << " ";
	visited[p] = 1;
	for (int i = 0; i < v.size(); i++) {
		pair<int, int> a = v[i];
		if (a.first == p && visited[a.second] == 0) {
			
			visited[a.second] = 1;
			dfs(a.second);
		}
		else if (a.second == p && visited[a.first] == 0) {
			
			visited[a.first] = 1;
			dfs(a.first);
		}
	}
}
void bfs(int p) {
		
		
		q.push(p);
		visited[p] = 1;
		while (!q.empty()) {
			cout << q.front() << " ";
			p = q.front();
			q.pop();
			//cout << "q size : " << q.size() << endl;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].first == p && visited[v[i].second] == 0) {
					q.push(v[i].second);
					visited[v[i].second] = 1;
				}
				else if (v[i].second == p && visited[v[i].first] == 0) {
					q.push(v[i].first);
					visited[v[i].first] = 1;
				}

			}
			
			
			
		}
		
		
		
		
}

int main() {
	
	cin >> n >> m >> f;
	

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >>a>> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	dfs(f);
	cout << "\n";
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
	}
	
	bfs(f);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}
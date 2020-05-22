#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<pair<int,int> > v;
int visited[1001] = {};


void dfs(int n) {
	//cout << "n : " << n << endl;
	visited[n] = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == n && visited[v[i].second] == 0) {
			dfs(v[i].second);
		}
	}
}
 

int main() {
	int n, m, count=0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
		v.push_back(make_pair(b,a));
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		if (visited[v[i].first] == 0) {
			dfs(v[i].first);
			count++;
			//cout << "count:" << count << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			count++;
		}
	}
	cout << count;
}
//in 8 11
//1 2 1
//1 3 2
//2 3 3
//2 4 4
//4 5 1
//4 6 2
//5 6 2
//5 8 2
//6 7 3
//7 8 4
//3 6 2
//
//out 17
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge {
	int p, q, cost;
};

const int MAX = 100;
vector<edge> el;
int v, e;
int parent[MAX];
int sum = 0;

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}

bool Union(int a, int b) {
	//a,b가 같은 트리에 없으면 합치고 true반환
	//같은트리에 있으면 false 반환;
	int ap = find(a);
	int bp = find(b);
	if (ap == bp) {
		return false;
	}
	else {
		parent[b] = ap;
		return true;
	}
}

bool compare(edge e1, edge e2) {
	return e1.cost < e2.cost;
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		edge t;
		cin >> t.p >> t.q >> t.cost;
		el.push_back(t);
	}
	
	sort(el.begin(), el.end(), compare);
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < el.size(); i++) {
		if (Union(el[i].p, el[i].q)) {
			sum += el[i].cost;
			cout << "cost: " << el[i].cost << endl;
		}
	}
	cout << sum;
}
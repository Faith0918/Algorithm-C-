#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
vector<int> makable;
vector<bool> visited;
void isMakable(int cnt, int candi) {
	for (int i = cnt; i < v.size(); i++) {
		if (!visited[i] && find(makable.begin(),makable.end(), candi+v[i])==makable.end()) {
			visited[i] = true;
			makable.push_back(candi + v[i]);
			isMakable(i, candi + v[i]);
			visited[i] = false;
		}
	}
	
}

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		visited.push_back(false);
	}
	sort(v.begin(), v.end());
	int answer = 1;
	
	isMakable(0, 0);
	sort(makable.begin(), makable.end());
	while (true) {
		if (find(makable.begin(), makable.end(), answer)==makable.end()) {
			break;
		}
		else {
			answer++;
		}
	}
	cout << answer;
}
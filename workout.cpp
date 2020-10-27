#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.second > p2.second;
}

int T, N, K;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		vector<int> v(N + 1);
		vector< pair< int , int > > d;
		
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
		}
// 1) calculate all differences and save.
		for (int i = 2; i <= N; i++) {
//Note : I don't know the relationship of variables, values, pointers, references, and tamplates.
			d.push_back(make_pair(i+1, v[i] - v[i - 1]));
		}
// 2) sort diffences between the sessions.
		sort(d.begin(), d.end(), cmp);
// 3) divide each elements by the last(minimum) nuber of difference.
		vector<pair<int, int>> d_d;
		for (int i = 0; i < d.size(); i++) {
			//TODO
		}
// 4) try to make the maximum number minimum by adding K sessionis in total.
// 4-0) while(k>0)
// 4-1) subtract the maximum element(s) min(difference between elements I calculated, # of addable sessions).
// 4-2) subtract k by min(difference between elements I calculated, # of addable sessions)
// 4-2) get the next ones
	}
}

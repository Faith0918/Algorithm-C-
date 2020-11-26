#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int anaswer;
int chosen;



int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < v.size()-1; i++) {
		chosen = v[i];
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] != v[j]) {
				anaswer++;
			}
		}
		
	}
	cout << anaswer;
}
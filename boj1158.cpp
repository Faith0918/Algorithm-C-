#include<iostream>
#include<vector>
using namespace std;

int main() {
	int k, n,pos;
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	pos = 0;
	cout << "<";
	while (!v.empty()) {
		
		if (pos + k - 1 > v.size() - 1) {
			
			pos = (pos + k - 1) % v.size();
		}
		else {
			pos = pos + k - 1;
		}
		if (v.size() == 1) {
			cout << v[pos];
			v.erase(v.begin() + pos);
		}
		else {
			cout << v[pos] << ", ";
			v.erase(v.begin() + pos);
		}
		
		
	}
	cout << ">";
}
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int a, p;

int power(int n, int p) {
	int ret = n;
	for (int i = 1; i <= p; i++) {
		ret = ret * n;
	}
	return ret;
}

int funct(int num) {
	int sum = 0;
	for (int i = 1000000; i >= 1; i = i / 10) {
		sum += power((num / i), p);
		num = num % i;
		//cout << "i : "<<i<<" sum : " << sum << " num : " << num << "\n";
	}
	return sum;
}

int main() {
	cin >> a >> p;
	vector<int> v;
	v.push_back(a);
	bool br = false;
	int idx = 0;
	while (1) {
		idx++;
		v.push_back(funct(v[idx - 1]));
		int new_num = v[v.size() - 1];
		for (int i = 0; i < idx; i++) {
			if (v[i] == new_num) {
				cout << i;
				br = true;
				break;
			}
		}
		if (br) {
			break;
		}
	}

}
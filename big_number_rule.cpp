#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K;
vector<int> numbers;
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}
	sort(numbers.begin(), numbers.end());
	int cnt = 0;
	int same = 0;
	int answer = 0;
	while (cnt < M) {
		if (same < K) {
			same++;
			answer += numbers[numbers.size() - 1];
		}
		else {
			answer += numbers[numbers.size() - 2];
			same = 0;
		}
		cnt++;
	}
	cout << answer;
	return answer;
}
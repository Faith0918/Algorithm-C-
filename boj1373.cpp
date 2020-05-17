//length를 모듈러 3을 취하면 더 쉽게 상위 3개의 string을 가공할 수 있다...
#include<iostream>
#include<stack>
using namespace std;

int main() {
	string input;
	char c;
	stack<char> s;
	stack<int> output;
	
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		//cout << "intput[" << i << "] = " << input[i]<<"\n";
		s.push(input[i]);
	}
	int count = 0;
	//cout << "stack size : " << s.size() << endl;
	while (!s.empty()) {
		int visited[3] = {};
		int number = 0;
		if (s.top() == '1') {
			visited[0] = 1;
			
		}
		s.pop();
		if (!s.empty()){
			if (s.top() == '1') {
				visited[1] = 1;
				
			}
			s.pop();
		}
		
		if (!s.empty()){
			if (s.top() == '1') {
				visited[2] = 1;
			}
			s.pop();
		}
		
		for (int i = 0; i < 3; i++) {
			if (visited[i] == 1) {
				number += 1 << i;
			}
		}
		//cout << number << endl;
		output.push(number);
		
	}
	while (!output.empty()) {
		cout << output.top();
		output.pop();
	}
}
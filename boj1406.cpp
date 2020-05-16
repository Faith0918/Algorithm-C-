//에디터
//STL list, iterator 사용
//iterator : list의 인덱스 개념
//           iterator는 >,< 연산자를 사용하지 않고, !=, = 연산자를 사용하여 비교한다.
#include<list>
#include<iostream>
#include<iterator>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	list<char> l;
	string s,cmd;
	char x;
	int n;
	
	cin >> s;
	cin >> n;
	
	for (int i = 0; i < s.size(); i++) {
		l.push_back(s[i]);
	}
	list<char>::iterator cursor = l.end();
	for (int i = 0; i < n; i++) {
		cin >>cmd;
		if (cmd == "L") {
			if (cursor != l.begin()) cursor--;
		}
		else if (cmd == "D") {
			if (cursor != l.end()) cursor++;
		}
		else if (cmd == "B") {
			if (cursor != l.begin()) cursor = l.erase(--cursor);
		}
		else if (cmd == "P") {
			cin >> x;
			l.insert(cursor, x);

		}
	}
	for (list<char>::iterator iter = l.begin(); iter != l.end(); iter++) {
		cout << *iter;
	}
	cout << endl;
}
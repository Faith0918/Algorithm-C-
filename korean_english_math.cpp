#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student {
	public:
		string name;
		int kor;
		int eng;
		int math;
		
};
bool cmp(Student& a, Student& b) {
	if (a.kor != b.kor) {
		return a.kor > b.kor;
	}
	else if (a.eng != b.eng) {
		return a.eng < b.eng;
	}
	else if (a.math != b.math) {
		return a.math > b.math;
	}
	else {
		return a.name < b.name;
	}
}
int main() {
	int n;
	cin >> n;
	vector<Student> l;
	for (int i = 0; i < n; i++) {
		Student s;
		string name;
		int kor, eng, math;
		cin >> s.name;
		cin >> s.kor;
		cin >> s.eng;
		cin >> s.math;
		l.push_back(s);

	}
	sort(l.begin(), l.end(), cmp);
	for (int i = 0; i < l.size(); i++) {
		cout << l[i].name << "\n";
	}
}
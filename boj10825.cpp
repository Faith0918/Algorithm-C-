#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
class Person{#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
class Person{
	public:
		string name;
		int math;
		int eng;
		int kor;
};
bool compare( Person &p1, Person &p2){
	return make_tuple(-p1.kor,p1.eng,-p1.math,p1.name)<make_tuple(-p2.kor,p2.eng,-p2.math,p2.name);
}
int main(){
	int n;
	cin>>n;
	vector<Person> v;
	for(int i = 1; i<=n; i++){
		Person p;
		cin>>p.name>>p.kor>>p.eng>>p.math;
		v.push_back(p);
	}
	sort(v.begin(),v.end(),compare);
	for(int i = 0; i<n; i++){
		cout<<v[i].name<<"\n";
	}
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int, string> p1, pair<int,string> p2){
	return p1.first<p2.first;
}
int main(){
	int n;
	vector<pair<int,string> > v;
	cin>>n;
	for(int i = 1; i<=n; i++){
		string name;
		int age;
		cin>>age>>name;
		v.push_back(make_pair(age,name));
	}
	stable_sort(v.begin(),v.end(),compare);
	for(int i = 0; i<n; i++){
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int compare(pair<int,int> &a, pair<int,int> &b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	else{
		return a.second<b.second;
	}
}
int main(){
	int N;
	vector<pair<int, int> > v;
	cin>>N;
	for(int i = 1; i<=N; i++){
		int x, y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end(), compare);
	for(int i =0; i<N; i++){
		int x = v[i].first;
		int y = v[i].second;
		printf("%d %d\n",x,y);
	}
}

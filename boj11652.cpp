//boj11652

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<long long,int> a, pair<long long,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	else{
		return a.second>b.second;
	}
	
}
int main(){
	
	int n;
	vector<long long > a;
	vector<pair<long long, int> > v;
	cin>>n;
	for(int i = 0; i<n; i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	//for (int i = 0; i < a.size(); i++) {
		//cout << a[i] << " ";
	//}
	long long max = 0;
	long long num = a[0];
	int count = 1;
	if (n == 1) {
		cout << num;
		return 0;
	}
	for(int i = 1; i<n; i++){
		if(a[i] == num){
			if(i==n-1){
				v.push_back(pair<long long, int>(num,count+1));
			}
			else{
				count++;
			}
			
		}
		else{
			v.push_back(pair<long long, int> (num,count));
			num = a[i];
			count = 1;
		}
	}
	sort(v.begin(),v.end(),cmp);
	cout<<v[0].first;
}

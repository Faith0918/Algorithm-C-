#include<iostream>
using namespace std;
int main(){
	int n;
	int p[10001];
	int d[10001];
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>p[i];
		d[i] = p[i];
		for(int j = 1; j<=i/2; j++){
			d[i] = max(d[i],d[i-j]+d[j]);
		}
	}
	
	cout<<d[n]<<endl;
}

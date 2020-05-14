#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N;
	int a[10001] = {};
	cin>>N;
	for(int i = 1; i<=N; i++){
		int num;
		cin>>num;
		a[num]++;
		
	}
	for(int i = 1; i<=10000; i++){
        for(int j = 1; j<=a[i]; j++){
            cout<<i<<"\n";
        }
		
	}
	

}

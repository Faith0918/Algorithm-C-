#include<iostream>
using namespace std;

int main(){
    int n, k;
    int d[201][201] = {};
    cin>>n>>k;
    for(int i = 1; i<=n;i++){
//    	cout<<i<<i<<i<<endl;
        d[i][1] = 1;
    }
    for(int i = 1; i<=n;i++){
//    	cout<<i<<i<<i<<endl;
        d[i][2] = i+1;
    }
    for(int i = 3; i<=k;i++){
//    	cout<<i<<endl;
        d[1][i] = d[1][i-1]+1;
        for(int j = 2;j<=n; j++){
            d[j][i] = (d[j-1][i]+d[j][i-1])%(int)1e9;
        }
    }
    cout<<d[n][k]%(int)1e9<<endl;
}

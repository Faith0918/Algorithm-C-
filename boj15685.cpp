#include<iostream>
using namespace std;

int n,x,y,d,g;
int dp[11][1025] = {};
int map[101][101] = {};
void dragonCurve(){
	dp[0][0] = d;
	if(g>0){
		for(int idx = 1; idx<=g; idx++){
			for(int j = 0; j<1<<(idx-1); j++){
				dp[idx][j] = dp[idx-1][j];
			}
			for(int j = (1<<idx)-1; j>=1<<(idx-1);j--){
				dp[idx][j] = (dp[idx][(1<<idx)-1-j]+1)%4;
			}
		} 
	}
	
}

void draw(){
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,-1,0,1};
	map[y][x] = 1;
	for(int i = 0; i<1<<g; i++){
		x+=dx[dp[g][i]];
		y+=dy[dp[g][i]];
		map[y][x] = 1;
	}
	
}

int main(){
	
	cin>>n;
	
	for(int i = 1; i<=n; i++){
		cin>>x>>y>>d>>g;
		dragonCurve();
		draw();
	}
	int count = 0;
	for(int i = 0; i<100; i++){
		for(int j = 0; j<100; j++){
			if(map[i][j]*map[i+1][j]*map[i][j+1]*map[i+1][j+1]!=0){
				count++;
			}
		}
	}
	cout<<count<<"\n";
}

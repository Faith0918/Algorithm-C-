//#13891 gear
#include<iostream>
#include<cmath>
using namespace std;
int w[5] = {0,};
bool visited[5];
char g[5][9];
int k;
void roll(int num, int wise){
	
	char temp = g[num][1];
	if(wise == 1){//clockwise
		g[num][1] = g[num][8];
		g[num][8] = g[num][7];
		g[num][7] = g[num][6];
		g[num][6] = g[num][5];
		g[num][5] = g[num][4];
		g[num][4] = g[num][3];
		g[num][3] = g[num][2];
		g[num][2] = temp;
	}
	else{//counter clockwise
		g[num][1] = g[num][2];
		g[num][2] = g[num][3];
		g[num][3] = g[num][4];
		g[num][4] = g[num][5];
		g[num][5] = g[num][6];
		g[num][6] = g[num][7];
		g[num][7] = g[num][8];
		g[num][8] = temp;
	}
}
void rotate(int num, int wise){
	w[num] = wise;
	visited[num] = true;
	if(num-1>=1&&visited[num-1] == false){
		if(g[num][7] != g[num-1][3]){
			rotate(num-1, wise*-1);
		}
	}
	if(num+1<=4&&visited[num+1] == false){
		if(g[num][3] != g[num+1][7]){
			rotate(num+1,wise*-1);
		}
	}
}
int main(){
	
	for(int i = 1; i<=4; i++){
		for(int j = 1; j<=8; j++){
			cin>>g[i][j];
		}
	}
	
	cin>>k;
	
	for(int i = 1; i<=k; i++){
		int a, b;
		cin>>a>>b;
		for(int j = 1; j<=4; j++){
			visited[j] = false;
			w[j] = 0;
		}
		rotate(a,b);
		for(int j = 1; j<=4; j++){
			if(visited[j]){
				roll(j,w[j]);
			}
		}
	}
	int sum = 0;
	for(int i = 1; i<=4; i++){
		if(g[i][1]=='1'){
			
			sum = sum + (1<<(i-1));
		}
	}
	cout<<sum<<endl;
}

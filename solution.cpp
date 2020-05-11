#include<iostream>
using namespace std;

int n, m, x, y, k;
int a[21][21] = {};
int dice[7] = {};

void move(int d){
	//east:1 west:2 south:3 north:4
	if(d == 1){
		int next_x = x+1;
		int next_y = y;
		if(next_x<=m){
			int temp = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = dice[1];
			dice[1] = temp;
			if(a[next_y][next_x] == 0){
				a[next_y][next_x] = dice[6];
			}
			else{
				dice[6] = a[next_y][next_x];
				a[next_y][next_x] = 0;
			}
			cout<<1111<<endl;
			x=next_x;
			y=next_y;
		}
	}
	else if(d == 2){
		int next_x = x-1;
		int next_y = y;
		if(next_x>=1){
			int temp = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = temp;
			if(a[next_y][next_x] == 0){
				a[next_y][next_x] = dice[6];
			}
			else{
				dice[6] = a[next_y][next_x];
				a[next_y][next_x] = 0;
			}
			cout<<2222<<endl;
			x=next_x;
			y=next_y;
		}
	}
	else if(d == 3){
		int next_x = x;
		int next_y = y+1;
		if(next_y<=n){
			int temp = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
			if(a[next_y][next_x] == 0){
				a[next_y][next_x] = dice[6];
			}
			else{
				dice[6] = a[next_y][next_x];
				a[next_y][next_x] = 0;
			}
			x=next_x;
			y=next_y;
			cout<<3333<<endl;
		}
	}
	else if(d == 4){
		int next_x = x;
		int next_y = y-1;
		if(next_y>=1){
			int temp = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = temp;
			if(a[next_y][next_x] == 0){
				a[next_y][next_x] = dice[6];
			}
			else{
				dice[6] = a[next_y][next_x];
				a[next_y][next_x] = 0;
			}
			x=next_x;
			y=next_y;
			cout<<4444<<endl;
		}
	}
	cout<<dice[1]<<endl;
}

int main(){
	
	cin>>n>>m>>x>>y>>k;
	x++;
	y++;
	for(int r = 1; r<=n ;r++){
		for(int c = 1; c<=m; c++){
			cin>>a[r][c];
		}
	}
	for(int i = 1; i<=k ; i++){
		int d;
		cin>>d;
		move(d);
	}
	
	
}


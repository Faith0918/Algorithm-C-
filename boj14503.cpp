#include<iostream>
#include<queue>
using namespace std;
class Robot{
	public : 
	int r;
	int c;
	int d;
	
};
int main(){
	int n, m,r,c,d;
	int map[51][51];
	int visited[51][51] = {};
	int dr[4] = {-1,0,1,0};
	int dc[4] = {0,1,0,-1};
	
	queue<Robot> q;
	cin>>n>>m;
	cin>>r>>c>>d;
	Robot robot;
	robot.r = r+1;
	robot.c = c+1;
	robot.d = d;
	q.push(robot);
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>map[i][j];
		}
	}
	int count = 0;
	int sum = 0;
	while(!q.empty()){
		Robot r = q.back();
		q.pop();
		if(visited[r.r][r.c]==0){
			count = 0;
			sum++;
			visited[r.r][r.c] = sum;
		}
		
		if(visited[r.r+dr[(r.d+3)%4]][r.c+dc[(r.d+3)%4]]==0 && map[r.r+dr[(r.d+3)%4]][r.c+dc[(r.d+3)%4]]==0){
			r.d = (r.d+3)%4;
			r.r += dr[r.d];
			r.c += dc[r.d];
			q.push(r);
		}
		else{
			if(count==4){
				if(map[r.r-dr[r.d]][r.c-dc[r.d]]==0 ){
					r.r -=dr[r.d];
					r.c -=dc[r.d];
					q.push(r);
					count = 0;
				}
				else{
//					cout<<r.r<<", "<<r.c<<endl;
					break;
				}
				
			}
			else{
				r.d = (r.d+3)%4;
				q.push(r);
				count++;
			}
			
		}
	}
	for(int i = 1;i<=n; i++){
		for(int j = 1; j<=m; j++){
//				cout<<visited[i][j]<<"	";			
		}
//		cout<<endl;
	}
	cout<<sum;
}

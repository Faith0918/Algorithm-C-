#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int n, l;
	cin>>n>>l;
	int map[201][101];
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>map[i][j];
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			map[i+n][j] = map[j][i];
		}
	}
	int sum = 0;
	for(int i = 1; i<=2*n; i++){
		int visited[n+1] = {};
		int j = 1;
		int h = map[i][j];
		int count = 1;
		
		bool available = true;
		while(j <n){
			j++;
			if(map[i][j] ==h){
				count++;
			}
			else if(map[i][j] == h+1){
				bool is_visited=false;
				for(int idx = j-1; idx>=j-l; idx--){
					if(visited[idx] == 1){
						is_visited = true;
					}
				}
				if(count>=l&&is_visited == false){
					h = h+1;
					count = 1;
					
				}
				else{
					available = false;
					break;
				}
				
			}
			else if(map[i][j] == h-1 ){
				if(j+l-1<=n){
					for(int k = 1; k<l; k++){
						
						if(map[i][k+j]!=h-1 ){
							available = false;
							break;//unavailable
						}
						else{
							visited[k+j] = 1;
						}
					}
					if(available){
						visited[j] = 1;
						h--;
					}
				}
				else{
					available = false;
					break;//unavailable
				}
				
			}
			
			if(abs(map[i][j]-h)>=2){
				break;
			}
			if(j == n&&available){
				
				sum++;
			}
					
		}
		
		
	}
	cout<<sum;
	
}

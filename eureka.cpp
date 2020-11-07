#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int K;
int num;
bool ans = false;
void dfs(int idx, int candi, int cnt){
	if(cnt == 3){
		if(candi == num){
			ans = true;
		}
		return;
	}else{
		for(int i = idx; i<=sqrt(num)*2; i++){
			int n = (i * (i+1) )/ 2;
			if(candi+n<=num){
				dfs(idx, candi+n, cnt+1);
			}
			
			
		}
	}
}

int main() {
	cin>>K;
	for(int i = 0; i<K;i++){
		cin>>num;
		ans = false;
		dfs(1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

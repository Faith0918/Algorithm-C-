#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int N;
int C;
deque<int> ans;
deque<int> a;
//input = a+b+c+a*100+b*10+c (0<a<=0 && 0<=b<=9 && 0<=c<=9)
//output = a*100+b*10+c;

void dfs(int candi, int index, int cnt){
    if(cnt == C ){
        if(candi == N){
            if(ans.size()==0){
                    ans = a;
            }
        }
        return;
    }else{
        
        for(int i = 0; i<10;i++){
            int tmp = candi + (pow(10, C-cnt-1) * i) + i;
            if(tmp<=N){
                a.push_back(i);
                dfs(tmp, i, cnt+1);
                a.pop_back();
            }
        }
        
    }
}

int main()
{
    cin >> N;
    C = log10(N)+1;
    dfs(0, 0, 0);
    if(ans.size()==0){
        cout<<0;
        return 0;
    }
    for(int i = 0; i<ans.size();i++){
        if(ans[i]==0 && i==0){
            continue;
        }
        cout << ans[i];
    }
    
    return 0;
}

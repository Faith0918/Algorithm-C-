maxx = -1000000000
minn = 1000000000



def dfs( cnt, candi):
    global maxx, minn
    if(cnt== len(number)-1):
        
        if(candi>maxx):
            maxx = candi
        if(candi<minn):
            minn = candi
        return
    else:
        if(op[0]>0):
            op[0]-=1
            dfs(cnt+1,candi+number[cnt+1])
            op[0]+=1
        if(op[1]>0):
            op[1]-=1
            dfs(cnt+1,candi-number[cnt+1])
            op[1]+=1
        if(op[2]>0):
            op[2]-=1
            dfs(cnt+1,candi*number[cnt+1])
            op[2]+=1
        if(op[3]>0):
            op[3]-=1
            dfs(cnt+1,int(candi/number[cnt+1]))
            op[3]+=1

n = int(input())
number = list(map(int,input().split()))
op = list(map(int,input().split()))
#print("op : "+str(op))
dfs(0,number[0])
print(maxx)
print(minn)
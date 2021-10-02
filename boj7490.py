t = int(input())

def dfs(cnt, candi, c, last_number):
    global n, ans
    if cnt == n:
        # print("candi : ",candi)
        if c == 0:
            ans.append(candi)
            return
    else:
        dfs(cnt+1, candi+"+"+str(cnt+1),c+cnt+1, cnt+1)
        if last_number>0:
            dfs(cnt+1, candi+" "+str(cnt+1),c-last_number+(last_number*10)+(cnt+1), (last_number*10)+(cnt+1))
        else:
            dfs(cnt+1, candi+" "+str(cnt+1),c-last_number+(last_number*10)-(cnt+1), (last_number*10)-(cnt+1))
        dfs(cnt+1, candi+"-"+str(cnt+1),c-(cnt+1), -(cnt+1))
        



for t_ in range(t):
    n = int(input())
    ans = []
    dfs(1,"1",1, 1)
    ans.sort()
    for a in ans:
        print(a)
    print()
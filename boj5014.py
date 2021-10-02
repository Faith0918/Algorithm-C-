from collections import deque
f, s, g, u, d = map(int, input().split())
q = deque()
q.append([s,0])
ans = 0
flag = False
visited = [0 for _ in range(f+1)]
visited[s] = 1
while len(q)>0:
    cur = q.popleft()
    if cur[0] == g:
        ans = cur[1]
        flag = True
        break
    else:
        n = cur[0] + u
        if n >=1 and n<=f and visited[n]==0:
            q.append([n,cur[1]+1])
            visited[n] = 1
        n = cur[0] - d
        if n>=1 and n<=f and visited[n]==0:
            q.append([n, cur[1]+1])
            visited[n] = 1

if flag == False:
    print("use the stairs")
else:
    print(ans)
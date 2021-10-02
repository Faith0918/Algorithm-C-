from collections import deque
def isAllVisited():
    global visited, n
    for i in range(1,n+1):
        if visited[i] == 0:
            return False
    # print(visited)
    return True 
n = int(input())
g = {}
minn = int(1e9)
candi = []
for i in range(1,n+1):
    g[i] = []
while True:
    a, b = map(int, input().split())
    if a == -1 and b == -1:
        break
    else:
        g[a].append(b)
        g[b].append(a)
for i in range(1, n+1):
    q = deque()
    visited = [0 for _ in range(n+1)]
    visited[i] = 1
    q.append([i, 0])
    # if i == 4:
    # print("here",i)
    score = 0
    flag = False
    while q:
        cur = q.popleft()
        # print("cur:",cur)
        if isAllVisited():
            # print("number",score)

            if minn > score:
                minn = score
                candi = [i]
            elif minn == score:
                candi.append(i)
            break
        for f in g[cur[0]]:
            if visited[f]==0:
                # print(f)
                q.append([f,cur[1]+1])
                score = cur[1]+1
                visited[f] = 1

print(minn, len(candi))
ans = ""
for c in candi:
    ans = ans+str(c)+" "
print(ans)
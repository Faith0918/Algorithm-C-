def dfs(p, cnt):
    global ans, visited, y, flag
    if p == y:
        ans = cnt
        flag= True
        return
    elif flag == False:
        for i in tree[p]:
            if visited[i] == 0:
                visited[i] = 1
                dfs(i, cnt+1)
                visited[i] = 0


n = int(input())
x, y = map(int, input().split())
m = int(input())
flag = False
tree = {}
for i in range(n):
    tree[i+1] = []
for i in range(m):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)
visited = [0 for _ in range(n+1)]
ans = 0
visited[x] = 1
dfs(x, 0)
if flag == False:
    ans = -1
print(ans)
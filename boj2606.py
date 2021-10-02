def dfs(idx):
  global virus, edges
  for c in edges[idx]:
    if virus[c] == 0:
        virus[c] = 1
        dfs(c)

n = int(input())
e = int(input())
edges = {}
for i in range(n):
  edges[i+1] = []
for i in range(e):
  a, b = map(int, input().split())
  edges[a].append(b)
  edges[b].append(a)
virus = [0 for _ in range(n+1)]
dfs(1)
virus[1] = 1
ans = 0
for i in range(1,n+1):
  if virus[i] == 1:
    ans+=1
# print(virus)
print(ans-1)
def dfs(c_r, c_c, cnt, pos):
    global n, possibility, visited, dr, dc, ans
    # print("cnt : ",cnt)
    if cnt == n:
        # print(pos, ans)
        ans += pos
        return
    else:
        for i in range(4):
            n_r = c_r + dr[i]
            n_c = c_c + dc[i]
            # print(n_r,n_c,visited[n_r][n_c],pos*possibility[i])
            if visited[n_r][n_c] == 0:
                # print("here")
                visited[n_r][n_c] = 1
                dfs(n_r,n_c, cnt+1, pos*possibility[i])
                visited[n_r][n_c] = 0


n, a, b,c,d = map(int, input().split())
possibility = [a/100,b/100,c/100,d/100]
# print(possibility)
simple_path = []

ans = 0

visited = [[0 for _ in range (40)] for _ in range(40)]
dr = [0,0,-1,1]
dc = [1,-1,0,0]
s_r = 20
s_c = 20
visited[s_r][s_c] = 1
dfs(s_r,s_c,0,1)

print(ans)

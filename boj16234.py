# boj 16234 인구이동 start 6:38
# 1) 국경선을 공유하는 두 나라 인구차이가 L이상R이하라면 국경선을 하루 연다.
# 2) 위 조건에 의해 열어야 하는 국경선이 모두 열렸다면, 인구이동을 시작한다.
# 3) 국경선이 열려있으면 연합을 이룬다
# 3-1) 연합을 이루고 있는 각 칸의 인구수 = (연합의 인구수) / (연합을 이루고 있는 칸의 개수)
# 4) 연합을 해체하고, 모든 국경선을 닫는다.
from collections import deque
def dfs(sr,sc):
    global n,l,r,board, flag, visited
    q = deque()
    q.append([sr,sc])
    visited[sr][sc] = True
    united = [[sr,sc]]
    summation = board[sr][sc]
    while q:
        c = q.popleft()
        cr = c[0]
        cc = c[1]
        dr = [0,0,1,-1]
        dc = [1,-1,0,0]
        for d in range(4):
            nr = cr+dr[d]
            nc = cc+dc[d]
            
            if 0<=nr<n and 0<=nc<n and visited[nr][nc]==False:
                diff = abs(board[cr][cc]-board[nr][nc])
                # print(diff)
                if l<=diff<=r:
                    q.append([nr,nc])
                    visited[nr][nc] = True
                    united.append([nr,nc])
                    summation+=board[nr][nc]
    # print(united)
    if len(united)>1:
        flag = True
        pop = (summation//len(united))
        # print(pop)
        for cur in united:
            cr = cur[0]
            cc = cur[1]
            board[cr][cc] = pop



n,l,r = map(int,input().split())
board = [ list(map(int,input().split())) for _ in range(n)]
ans = 0
while True:
    visited = [[False for _ in range(n)] for _ in range(n)]
    flag = False
    for i in range(n):
        for j in range(n):
            if visited[i][j] == False:
                dfs(i,j)
    if flag == False:
        break
    else:
        ans+=1
print(ans)
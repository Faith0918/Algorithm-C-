import pdb
from collections import deque
a = [4,2]
total_l = 1
for x in a:
    total_l *= x
board = [[0 for _ in range(total_l)] for _ in range(total_l)]
count = 1
dr = [0,1,0,-1]
dc = [1,0,-1,0]
def paint(start, leng):
    global board
    global count
    global total_l
    d = 0
    s_r, s_c = start
    q = deque()
    q.append(start)
    board[s_r][s_c] = count
    count+=1
    flag = False
    while True:
        if len(q) ==0:
            break
        c_r, c_c = q.popleft()
        n_r = c_r + dr[d]
        n_c = c_c + dc[d]
        if s_r <= n_r < s_r + leng and s_c <= n_c < s_c + leng:
            if board[n_r][n_c] == 0:
                flag = False
                board[n_r][n_c] = count
                count +=1
                q.append([n_r,n_c])
            else:
                if flag:
                    break
                else:
                    d = (d+1)%4
                    q.append([c_r,c_c])
                    flag = True
        else:
            d = (d+1)%4
            q.append([c_r,c_c])


def dfs(cnt, start, leng):
    if cnt == 0:
        # print("paint")
        paint(start, leng)
    else:
        c_r, c_c = start
        n_l = leng // a[cnt]
        # print("n_l", a[cnt], n_l, a[cnt])
        visited = [[False for _ in range(a[cnt])] for _ in range(a[cnt])]
        # print(visited)
        q = deque()
        q.append([0,0])
        d = 0
        dfs(cnt-1, start, n_l)
        visited[0][0] = True
        flag = False
        while q:
            
            c_r, c_c = q.popleft()
            # print(visited, d)
            # print("cur",c_r, c_c)
            n_r = c_r + dr[d]
            n_c = c_c + dc[d]
            # print("next r c",n_r, n_c)
            # pdb.set_trace()
            if 0 <= n_r < a[cnt] and 0<= n_c < a[cnt]:
                if visited[n_r][n_c] == False:
                    flag= False
                    visited[n_r][n_c] = True
                    q.append([n_r, n_c])
                    dfs(cnt-1, [start[0] +n_r*n_l, start[1] + n_c*n_l], n_l)
                else:
                    if flag:
                        break
                    else:
                        d = (d+1)%4
                        q.append([c_r,c_c])
                        flag = True
            else:
                d = (d+1)%4
                q.append([c_r,c_c])

dfs(len(a)-1, [0,0], total_l)
for r in range(total_l):
    print(board[r])

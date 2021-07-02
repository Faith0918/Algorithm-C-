from collections import deque
dr = [0,0,1,-1]
dc = [1,-1,0,0]
def find_dist(r,c,r_,c_):
    global mapp, n
    visited = [[0 for _ in range(n)] for _ in range(n)]
    # print(visited)
    # print(r,c)
    q = deque()
    q.append([r,c, 0])
    visited[r][c]=1
    while len(q)>0:
        cur_loc = q.popleft()
        c_r = cur_loc[0]
        c_c = cur_loc[1]
        c_dist = cur_loc[2]
        if c_r == r_ and c_c == c_:
            return c_dist
        for d in range(4):
            n_r = c_r + dr[d]
            n_c = c_c + dc[d]
            if n_r>=0 and n_r<n and n_c>=0 and n_c<n and mapp[n_r][n_c] == 0 and visited[n_r][n_c] ==0:
                q.append([n_r,n_c,c_dist+1])
                visited[n_r][n_c] = 1
    return int(1e9)

def find_nearest(t_r, t_c):
    minn = int(1e9)
    idx = -1
    for i, p_ in enumerate(p):
        d = find_dist(t_r,t_c,p_[0],p_[1])
        if minn>d:
            idx = i
            minn = d
        
    return idx, minn
n, m, f = map(int, input().split())

mapp = []
p = []
flag = True
for i in range(n):
    l = list(map(int, input().split()))
    mapp.append(l)

t_r, t_c = map(int, input().split())
t_r -=1
t_c -=1
for i in range(m):
    l = list(map(int, input().split()))
    for d in range(4):
        l[d] = l[d]-1
    p.append(l)
p = sorted(p, key = lambda x: (x[0],x[1]))
while len(p)>0:
    p_idx, dist = find_nearest(t_r,t_c)
    if p_idx == -1:
        flag = False
        break
    f -= dist
    if f<=0:
        flag = False
        break
    cur_p = p[p_idx]
    t_r = cur_p[0]
    t_c = cur_p[1]
    p_d = find_dist(t_r,t_c,cur_p[2],cur_p[3])
    if p_d <= f:
        t_r = cur_p[2]
        t_c = cur_p[3]
        f += p_d
        p.pop(p_idx)
    else:
        flag = False
        break
if flag == False:
    print(-1)
else:
    print(f)
    
from collections import deque
def melt_exposed():
    global m, r, c
    for r_ in range(r):
        for c_ in range(c):
            if m[r_][c_] == -1:
                m[r_][c_] = 0
r, c = map(int, input().split())
m = [[] for _ in range(r)]
air = []
time = 0
cheeseSize = 0
explosedCheese = 0
dr = [0,0,1,-1]
dc = [1,-1,0,0]
for r_ in range(r):
    l = list(map(int, input().split()))
    m[r_] = l
    for c_ in range(c):
        if r_ == 0 or c_ == 0 or r_ == r-1 or c_ ==c-1:
            air.append([r_,c_])
        if l[c_] == 1:
            cheeseSize+=1
while True:
    if cheeseSize == explosedCheese:
        break
    time+=1
    # print("time : ",time, cheeseSize, explosedCheese)
    cheeseSize -= explosedCheese
    melt_exposed()
    explosedCheese = 0
    q = deque()
    for a in air:
        q.append(a)
    # print(q)
    while q:
        cur = q.popleft()
        c_r = cur[0]
        c_c = cur[1]
        for d in range(4):
            n_r = c_r + dr[d]
            n_c = c_c + dc[d]
            if n_r>0 and n_r<r and n_c>0 and n_c<c:
                if m[n_r][n_c] == 1:
                    m[n_r][n_c] = -1
                    explosedCheese +=1
                    air.append([n_r, n_c])
                elif m[n_r][n_c] == 0 and [n_r,n_c] not in air:
                    air.append([n_r, n_c])
                    q.append([n_r,n_c])
            



print(time)
print(cheeseSize)
from collections import deque

m, n, h = map(int, input().split())
box = [[[0 for _ in range(m)] for _ in range(n)] for _ in range(h)]
ripe_tomatos = deque()
num_unripe = 0
for h_ in range(h):
    for n_ in range(n):
        l = list(map(int, input().split()))
        box[h_][n_] = l
        for m_, tomato in enumerate(l):
            if tomato == 1:
                ripe_tomatos.append([h_, n_, m_, 0])
            elif tomato == 0:
                num_unripe +=1
ans = 0
dm = [0,0,0,0,1,-1]
dn = [0,1,0,-1,0,0]
dh = [1,0,-1,0,0,0]
flag = False
while len(ripe_tomatos)>0:
    # print("cur_tomato : ",cur_tomato)
    if num_unripe == 0:
        flag = True
        break
    else:
        cur_tomato = ripe_tomatos.popleft()
        for d in range(6):
            n_h = cur_tomato[0] + dh[d]
            n_n = cur_tomato[1] + dn[d]
            n_m = cur_tomato[2] + dm[d]
            if n_h >=0 and n_h<h and n_n>=0 and n_n<n and n_m>=0 and n_m<m and box[n_h][n_n][n_m] == 0:
                num_unripe -=1
                # print([n_h, n_n, n_m, cur_tomato[3]+1])
                ripe_tomatos.append([n_h, n_n, n_m, cur_tomato[3]+1])
                # print("Q : ",ripe_tomatos)
                box[n_h][n_n][n_m] = 1

if flag == False:
    ans = -1
else:
    ans = ripe_tomatos[-1][3]
# print(ripe_tomatos)
print(ans)
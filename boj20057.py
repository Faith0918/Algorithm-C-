# 20057 마법사 상어와 토네이도
'''
1) 토네이도를 시전
1.1) 격자의 가운데부터 이동 시작.
1.2) 한번의 한칸 이동
1.3) 한칸 이동할 때마다 모래는 일정한 비율로 흩날린다.
'''
from collections import deque
import pdb
import math
def skill_tornado():
    global board, n,dr,dc
    # 격자의 가운데 구하기
    start = n//2
    q = deque()
    q.append([start,start,0])
    # 한번에 한칸 이동
    cur_length = 1
    check = 0
    while q:
        # pdb.set_trace()
        cur = q.popleft()
        # print(cur)
        cr = cur[0]
        cc = cur[1]
        d = cur[2]
        if cr==0 and cc ==0:
            break
        if check>0 and check%cur_length==0:
            d = (d+1)%4
        if check== 2*cur_length:
            check = 0
            cur_length = cur_length + 1
        for i in range(1,cur_length+1):
            # 한칸씩 움직이기
            # print("go 1 block")
            nr = cr+dr[d]
            nc = cc+dc[d]
            
            # print("spread in node nr,nc,d",d,nr,nc)
            # print("cur length:",cur_length)
            check += 1
            
            # print("before spreading")
            # for rr in range(n):
            #     print(board[rr])
            spread_sand(cr,cc,nr,nc,d)
            # print("after spreading")
            # for rr in range(n):
            #     print(board[rr])
            if nr==0 and nc == 0:
                break
            cr = nr
            cc =nc
        q.append([nr,nc,d])
        # break
        
def get_answer():
    global board,n,answer
    for r in range(n):
        # print(board[r])
        for c in range(n):
            answer-= board[r][c]
    # 모래 뿌리기
import copy   
def spread_sand(cr,cc,nr,nc,d):
    global board, n, dr,dc, answer
    # 해당 위치의 모래의 양을 구한다.
    sand_spreaded = 0
    amt_sand = copy.deepcopy(board[nr][nc])
    board[nr][nc]=0
    a = [nr+dr[d],nc+dc[d]]
    # 총 10개의 위치를 구한다.[c,c,n*2,n*2,n,n,a,a,a]
    nodes= [[cr,cc],[nr,nc],a]
    node_idx = [0,0,1,1,1,1,2,2]
    amt = [1,1,2,2,7,7,10,10]
    l = [1,-1,2,-2,-1,1,-1,1]
    nd = (d+1)%4
    for i in range(len(node_idx)):
        node = nodes[node_idx[i]]
        # pdb.set_trace()
        noder = node[0] + dr[nd]*l[i]
        nodec = node[1] + dc[nd]*l[i]
        # print("here",noder,nodec, amt[i],math.trunc(amt_sand*amt[i]/100))
        if 0<=noder<n and 0<=nodec<n:
            board[noder][nodec]+=math.trunc(amt_sand*amt[i]/100)
        sand_spreaded += math.trunc(amt_sand*amt[i]/100)
    na = [a[0]+dr[d],a[1]+dc[d]]
    if 0<=na[0]<n and 0<=na[1]<n:
        board[na[0]][na[1]]+= math.trunc(amt_sand*5/100)
    sand_spreaded+=math.trunc(amt_sand*5/100)
    if 0<=a[0]<n and 0<=a[1]<n:
        # print(board[a[0]][a[1]],amt_sand-sand_spreaded,amt_sand,sand_spreaded)
        board[a[0]][a[1]]+=(amt_sand-sand_spreaded)
    # else:
    #     answer+= amt_sand-sand_spreaded
    # 해당 위치가 보드를 넘어가면 답에 더한다.
    # 보드를 넘어가지 않으면 원래 있던 모래에 더해준다.
    
dr = [0,1,0,-1]
dc = [-1,0,1,0]
n = int(input())
board = [list(map(int,input().split())) for _ in range(n)]
answer = 0
for r in range(n):
    for c in range(n):
        answer+=board[r][c]

skill_tornado()
get_answer()
print(answer)

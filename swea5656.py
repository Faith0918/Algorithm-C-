#start 11:30 end: 1:12 total 1h42m
from collections import deque
import copy
# import pdb
t = int(input())
# 첫 벽돌 찾기
def find_first_brick(cc):
    global n,c,r,board_q
    cr = len(board_q[cc])-1
    return [cc,cr]
def select_bricks(first,debug=False): # bfs
    global n,c,r,board_q
    # if debug:
    #     pdb.set_trace()
    selected_list = [[] for _ in range(c)]
    visited = [[False for _ in range(r)] for _ in range(c)]
    dr = [1,0,0,-1]
    dc = [0,1,-1,0]
    q = deque()
    q.append(first)
    fc,fr = first
    visited[fc][fr]=True
    selected_list[fc].append(fr)
    
    while q:
        cc,cr = q.popleft()
        cn = board_q[cc][cr]
        for d in range(4):
            for i in range(1,cn):
                nc = cc+dc[d]*i
                nr = cr+dr[d]*i
                if 0<=nc<len(board_q) and 0<=nr<len(board_q[nc]):
                    if visited[nc][nr]==False:
                        selected_list[nc].append(nr)
                        q.append([nc,nr])
                        visited[nc][nr]=True
                    else:
                        continue
                elif 0<=nc<len(board_q):
                    continue
                else:
                    break
    return selected_list

def remove_bricks(selected_list):
    global n,c,r,board_q
    for cc, l in enumerate(selected_list):
        l.sort(reverse=True)
        for idx, cr in enumerate(l):
            del board_q[cc][cr]
def count_brick(board_q):
    global n,c,r
    cnt = 0
    for q in board_q:
        cnt+=len(q)
    return cnt
def dfs(cnt):
    global n,c,r,board_q,minimum
    if cnt == n:
        if count_brick(board_q)<minimum:
            minimum = count_brick(board_q)
    else:
        isNotEmpty = False
        for cc in range(c):
            if len(board_q[cc])>0:
                isNotEmpty = True
                first = find_first_brick(cc)
                selected_list = select_bricks(first)
                backup_board = copy.deepcopy(board_q)
                remove_bricks(selected_list)
                dfs(cnt+1)
                board_q = backup_board
        if isNotEmpty == False:
            minimum = 0
            return
for test_case in range(1,t+1):
    global n,c,r,board_q,minimum
    minimum = 1e9
    n,c,r = map(int,input().split())
    board = [list(map(int,input().split())) for _ in range(r)]
    board_q = []
    for cc in range(c):
        cur_col = deque()
        for cr in range(r-1,-1,-1):
            if board[cr][cc]==0:
                break
            else:
                cur_col.append(board[cr][cc])
        board_q.append(cur_col)
        # print(cur_col)
    dfs(0)
    result = "#"+str(test_case)+" "+str(minimum)
    print(result)


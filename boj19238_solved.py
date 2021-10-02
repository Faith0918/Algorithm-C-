# boj 19238 스타트택시
# M명의 승객을 나른다.
# 1) 승객을 고른다
# 1.1) 현재 위치에서 최단거리가 가장 짧은 승객
# 1.2) 행번호, 열번호 작은 승객
# 2) 승객을 이동시킨다.((BFS))
# 2.1) 승객이 있는 위치로 이동할 거리를 구한다.
# 2.2) 택시를 목적지로 이동시킨다.
# 2.3) 1칸 이동 시 1만큼 연료를 사용한다.
# 2.4) 연료가 충전된다.
from collections import deque
import copy
def find_passenger():
    # 승객을 고른다
    global passengers, taxi
    minimum = int(1e9)
    l = []
    passenger_idx = 0
    for i, passenger in enumerate(passengers):
        d = get_distance(taxi, passenger[:2], minimum)
        r = passenger[0]
        c = passenger[1]
        if minimum>d:
            minimum = d
            l = [[d,r,c,i]]
        elif minimum == d:
            l.append([d,r,c,i])
    l = sorted(l, key = lambda x:(x[0],x[1],x[2]))
    return l[0][3]
def move_passenger(passenger):
    global fuel, taxi
    # 승객을 이동시킨다.((BFS))
    # print("before")
    a = get_distance(taxi, passenger[:2], int(1e9))
    # print("after")
    # print(taxi, passenger, a)
    b = get_distance(passenger[:2], passenger[2:], int(1e9))
    if a+b>fuel:
        # print(passenger, a, b, fuel)
        return False
    else:
        # 연료를 충전하고, 택시를 움직인다.
        # print(taxi, passenger, a, b, fuel)
        fuel +=(b-a)
        taxi = passenger[2:]
        return True


def get_distance(a, b, m):
    # 최단거리 찾기((BFS))
    global board,n
    visited = [[False for _ in range(n)] for _ in range(n)]
    
    q = deque()
    q.append(a+[0])
    dr = [0,1,-1,0]
    dc = [1,0,0,-1]
    while q:
        c = q.popleft()
        cr = c[0]
        cc = c[1]
        cnt = c[2]
        # visited[cr][cc] = True
        if cr ==b[0] and cc == b[1]:
            return cnt
        if cnt < m:
            for d in range(4):
                nr = cr + dr[d]
                nc = cc + dc[d]
                if 0<=nr<n and 0<=nc<n and board[nr][nc]==0 and visited[nr][nc] == False:
                    q.append([nr,nc,cnt+1])
                    visited[nr][nc] = True
                    
    return int(1e9)

import sys
n,m,fuel = map(int, input().split())
board = [list(map(int,input().split())) for _ in range(n)]
taxi = list(map(int,input().split()))
passengers = [list(map(int,sys.stdin.readline().split())) for _ in range(m)]
for passenger in passengers:
    for j in range(4):
        passenger[j]-=1
for i in range(2):
    taxi[i]-=1
isAvailable = True
for i in range(m):
    idx = find_passenger()
    passenger = passengers[idx]
    if move_passenger(passenger) == False:
        print(-1)
        isAvailable = False
        break
    del passengers[idx]
if isAvailable:
    print(fuel)

#boj 14891 gears start 5:56 finished: 7:08

from collections import deque
import copy
import pdb

# 1) 회전해야하는 톱니바퀴들의 인덳스와 방향을 찾는다.
# 2) 톱니바퀴를 한번에 주어진 방향으로 회전시킨다.

def get_moving_gears(si, sd):
    global gears
    # 현재의 오른쪽, 왼쪽을 체크한다.
    # 오른쪽의 경우 현재의 2번, 오른쪽의 6번이 서로 다르다면, 현재와 반대방향으로 오른쪽을 회전한다.
    # 왼쪽의 경우 현재의 6번, 왼쪽의 2번이 서로 다르다면, 현재의 반대방향으로 왼쪽을 회전한다.
    visited = [False for _ in range(4)]
    moving_gears = []
    q = deque()
    q.append([si,sd])
    moving_gears.append([si,sd])
    visited[si] = True
    while True:
        if len(q)==0:
            break
        #direction으로 계속 유지를 하면서 push해야한다. 양쪽으로 가면 안됨.
        ci,cd = q.popleft()
        ri = ci+1
        if ri<4 and gears[ci][2]!=gears[ri][6] and visited[ri]==False:
            moving_gears.append([ri,-cd])
            visited[ri]=True
            q.append([ri,-cd])
        li = ci-1
        # print(li, ci, gears)
        if li>=0 and gears[ci][6]!=gears[li][2] and visited[li] == False:
            moving_gears.append([li,-cd])
            visited[li] = True
            q.append([li,-cd])
    return moving_gears

def move_gears(moving_gears):
    global gears
    for i, d in moving_gears:
        gears[i].rotate(d)

def get_score():
    global gears
    answer = 0
    for i, gear in enumerate(gears):
        answer += gear[0]<<i
    return answer
gears_str = [str(input()) for _ in range(4)]
gears = []
for s in gears_str:
    q = deque()
    for i in range(len(s)):
        q.append(int(s[i]))
    gears.append(q)
    
# gears = [deque(map(int,input().split())) for _ in range(4)]
n = int(input())
for i in range(n):
    si, sd = map(int,input().split())
    moving_gears = get_moving_gears(si-1,sd)
    # print("moving gears",moving_gears)
    # print("before moving\n",gears)
    move_gears(moving_gears)
    # print("after moving\n",gears)
score = get_score()
print(score)
# 20057 마법사 상어와 토네이도
'''
1) 토네이도를 시전
1.1) 격자의 가운데부터 이동 시작.
1.2) 한번의 한칸 이동
1.3) 한칸 이동할 때마다 모래는 일정한 비율로 흩날린다.
'''
from collections import deque
def skill_tornado():
    global board, n
    dr = [0,1,0,-1]
    dc = [-1,0,1,0]
    # 격자의 가운데 구하기
    start = n//2
    q = deque()
    q.append([start,start,0])
    # 한번에 한칸 이동
    cur_length = 1
    check = 1
    while q:
        cur = q.popleft()
        cr = cur[0]
        cc = cur[1]
        cd = cur[2]
        if cr==0 and cc ==0:
            break
        if check%cur_length==0:
            d = (d+1)%4
        if check== 2*cur_length:
            check = 0
            cur_length = cur_length + 1
        for i in range(cur_length):
            # 한칸씩 움직이기
            print("go 1 block")
            nr = cr+dr[d]
            nc = cc+dr[d]
            check += 1
            spread_sand(nr,nc,d)
        q.append([nr,nc,d])

    # 모래 뿌리기
    
def spread_sand(nr,nc,d):
    global board, n
    # 해당 위치의 모래의 양을 구한다.
    amt_sand = board[nr][nc]
    # 총 10개의 위치를 구한다.
    amt = [1,1,2,2,5,7,7,10,10]
    difr = []
    difc = []
    # 해당 위치가 보드를 넘어가면 답에 더한다.
    # 보드를 넘어가지 않으면 원래 있던 모래에 더해준다.
    
n = int(input())
board = [list(map(int,input().split())) for _ in range(n)]
answer = 0
skill_tornado()
print(answer)

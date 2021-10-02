# boj 5212 지구온난화
# 섬 중 주변에 섬이 2개 이상인지 체크한다.
# 1) 2개 이상이면, 놔둔다.
# 2) 그렇지 않으면, 바다로 바꾼다.
# 섬의 가장 왼, 오, 위, 아래를 구한다.
# 그만큼만으로 자른다.
import copy
r,c = map(int,input().split())
board = [str(input()) for _ in range(r)]
new_board = copy.deepcopy(board)
minimum = [r,c]
maximum = [-1,-1]
for i in range(r):
    for j in range(c):
        if board[i][j]=='X':
            #섬이다.
            cnt = 0
            dr = [0,0,-1,1]
            dc = [1,-1,0,0]
            for d in range(4):
                nr = i+dr[d]
                nc = j+dc[d]
                if 0<=nr<r and 0<=nc<c and board[nr][nc]=='X':
                    cnt+=1
            if cnt>1:
                # print("here")
                # print(i,j)
                minimum[0] = min(minimum[0],i)
                minimum[1] = min(minimum[1],j)
                maximum[0] = max(maximum[0],i)
                maximum[1] = max(maximum[1],j)
            else:
                if j== c-1:
                    new_board[i] = new_board[i][:j]+'.'
                else:
                    new_board[i] = new_board[i][:j]+'.'+new_board[i][j+1:]
# print(minimum, maximum)
# print("="*10)
# for i in range(r):
#     print(new_board[i])
# print("="*10)
for i in range(minimum[0], maximum[0]+1):
    print(new_board[i][minimum[1]:maximum[1]+1])
    # for j in range(minimum[1],maximum[1]+1):
    #     print(board[i])

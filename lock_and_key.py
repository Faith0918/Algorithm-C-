# 솔루션
# 1) M*2 + N 크기의 보드를 만들고 중앙에 좌물쇠를 배치한다.
# 2) key를 4번 돌려가며 차례로 이동시킨다
# 3) 위에서 아래로 열쇠를 이동했을때 중앙의 키가 모두 1이되면 unlock
# def rotate90(arr): # 90도 돌리기
# def attach(x, y, M, key, board): # 열쇠 넣어보기
# def detach(x, y, M, key, board): # 열쇠 빼기
# def check(board, M, N): # 모두 1인지 확인
def attach(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x+i][y+j] += key[i][j]

def detach(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x+i][y+j] -= key[i][j]

def rotate90(arr):
    return list(zip(*arr[::-1]))

def check(board, M, N):
    for i in range(N):
        for j in range(N):
            if board[M+i][M+j] != 1:
                return False;
    return True
def solution(key, lock):
    M,N = len(key), len(lock)
    board = [[0] * (M*2 + N) for _ in range(M*2 + N)]
    #자물쇠 중앙 배치
    for i in range(N):
        for j in range(N):
            board[M+i][M+j] = lock[i][j]
    
    rotated_key = key
    #모든 방향(4번 루프)
    for _ in range(4):
        rotated_key = rotate90(rotated_key)
        for x in range(1, M+N):
            for y in range(1, M+N):
                #열쇠 넣어보기
                attach(x,y,M,rotated_key, board)
                #lock 가능 check
                if check(board,M,N) :
                    return True
                #열쇠 빼기
                detach(x,y,M,rotated_key,board)
    return False

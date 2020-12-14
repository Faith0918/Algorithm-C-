# 오답노트 : 같은 x, y 에 기둥과 보가 오는 경우가 있어서 이렇게 하면 안된다.

def Execute(x,y,a,b,arr):
    if b ==1 : # 설치
        if a == 0 : # 기둥
            if y == 1 or arr[y][x-1] == 1 or arr[y-1][x] == 0: #바닥/ 보의 한쪽 끝/ 기둥 위에 있으면 설치
                
                arr[y][x] = 0
        else: #보
            if arr[y-1][x] == 0 or (arr[y][x-1] ==1 and arr[y][x+1] ==1) or arr[y-1][x+1]==0:
                arr[y][x] = 1
    else: # 제거
        if a == 0: # 기둥
            if arr[y+1][x] != 0 or (arr[y+1][x] !=1 and arr[y+1][x-1] != 1): # 기둥 위 아무 건축물도 없을 때만 제거 가능
                arr[y][x] = -1
        else: # 보
            if arr[y][x-1] != 1 and arr[y][x+1] != 1: 
                arr[y][x] = -1


def solution(n, build_frame):
    answer = []
    arr = [[-1]*(n+3) for _ in range(n+3)]
    for x, y, a, b in build_frame:
        if x >=0 and x <=n and y >=0 and y <=n:
            Execute(x+1,y+1,a,b,arr)
    
    for c in range(n+2):
        for r in range(n+2):
            if arr[r][c] >=0:
                answer.append([c-1,r-1,arr[r][c]])
    print(answer)
    return answer

if __name__ == "__main__":
    n = 2
    build_frame = [[0,0,0,1],[1,0,0,1],[0,1,1,1], [0,1,0,1]]
    solution(n, build_frame)
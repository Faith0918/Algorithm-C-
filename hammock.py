def Execute(x,y,a,b,arr):
    if b ==1 : # 설치
        if a == 0 : # 기둥
            if y == 0 or arr[y][x-1] == 1 or arr[y-1][x] == 0: #바닥/ 보의 한쪽 끝/ 기둥 위에 있으면 설치
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
    print("SS")
    arr = [[-1]*6 for _ in range(1001)]
    for x, y, a, b in build_frame:
        Execute(x,y,a,b,arr)
    
    for c in range(6):
        for r in range(1001):
            if arr[r][c] >=0:
                answer.append([c,r,arr[r][c]])
    print(answer)
    return answer
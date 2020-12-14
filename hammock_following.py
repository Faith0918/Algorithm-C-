#Set 내부에서 item을 add 하고 remove 하는 식으로 동작
#Python 정렬함수(sorted) ref : https://blog.naver.com/timtaeil/221426580068
def impossible(result):
    col, row = 0,1
    for x,y,a in result:
        if a == col: #기둥일 때
            if y != 0 and (x,y-1,col) not in result and\
             (x-1,y,row) not in result and (x,y,row) not in result:
                return True
        else: #보일 때
            if (x,y-1, col) not in result and (x+1,y-1,col) not in result and \
                not ((x-1,y,row) in result and (x+1,y,row) in result):
                return True
    return False




def solution(n, build_frame):
    result = set()
    for x, y, a, b in build_frame:
        item = (x,y,a)
        if b: #추가일 때
            result.add(item)
            if impossible(result):
                result.remove(item)
        elif item in result:
            result.remove(item)
            if impossible(result):
                result.add(item)
        
        answer = map(list, result)

        return sorted(answer, key = lambda x : (x[0], x[1], x[2]))

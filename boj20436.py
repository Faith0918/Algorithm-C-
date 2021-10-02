# boj 20436 ZOAC3
# 1)첫번째줄에는 두 알파벳 소문자 sL,sR이 주어진다.
# sL,sR은 각각 왼손 검지송가락, 오른손 검지손가락의 처음 위치이다.
# 입력으로 주어진 문자열을 출력하는 데에 걸리는 시간의 최솟값을 출력한다.
def get_distance(x,y):
    return abs(x[0]-y[0])+abs(x[1]-y[1])

keyboard = [['q','w','e','r','t','y','u','i','o','p'],['a','s','d','f','g','h','j','k','l'],['z','x','c','v','b','n','m']]
l, r = map(str, input().split())
d = {}
s = str(input())
for rr in range(len(keyboard)):
    for cc in range(len(keyboard[rr])):
        d[keyboard[rr][cc]] = [rr,cc]
ans = 0
# print(d)
r = d[r]
l = d[l]
# import pdb
for i in range(len(s)):
    # pdb.set_trace()
    target = d[s[i]]
    tr = target[0]
    tc = target[1]
    if ( tc>4 and tr<2 ) or ( tr == 2 and tc>3):
        dist = get_distance(target,r)
        r = target
    else:
        dist = get_distance(target,l)
        l = target
    ans+=dist+1
print(ans)
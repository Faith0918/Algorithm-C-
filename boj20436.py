<<<<<<< HEAD
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
=======
def distance(p1, p2):
    return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])

def dfs(count, c_l, c_r, candi):
    global min_n
    if count == len(s):
        if candi<min_n:
            min_n = candi
        return
    else:
        goal = d[s[count]]
        
        cur_l = d[c_l]
        cur_r = d[c_r]
        # left hand
        if s[count] in left_keyboard:
            dfs(count+1, s[count], c_r, candi + distance(cur_l, goal)+1)
        # right hand
        else:
            dfs(count+1, c_l, s[count], candi + distance(cur_r, goal)+1)

left_right = str(input())
l, r = left_right.split()
s = str(input())
d = {}
keyboard = ['qwertyuiop','asdfghjkl','zxcvbnm']
left_keyboard = ['q','w','e','r','t','a','s','d','f','g','z','x','c','v']
for r_, row in enumerate(keyboard):
    for c_, cha in enumerate(row):
        d[cha] = [r_,c_]

min_n = int(1e9)

dfs(0, l, r, 0)
print(min_n)
>>>>>>> b32b440baa88a71ddab59aa5e2d3c53823ae48e8

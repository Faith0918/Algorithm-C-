# boj 2503 숫자야구 start 6:12 end 6:47 (30m)
import pdb
def count_s(l,s):
    # pdb.set_trace()
    a = 0
    for i in range(3):
        # print("count s:",l[i] == s[i], l[i], int(s[i]), s)
        if l[i] == int(s[i]):
            a += 1
    return a
def count_b(l,s):
    a = 0
    for i in range(3):
        # print(s[i] in l)
        if int(s[i]) in l and l[i] != int(s[i]) :
            a+=1
    return a

from itertools import permutations
n = int(input())
quizes = [list(map(int,input().split())) for _ in range(n)]
a = [1,2,3]
permute = []
for i in range(1,10):
    for j in range(1,10):
        if j == i:
            continue
        for k in range(1,10):
            if k == j or k == i:
                continue
            permute.append([i,j,k])
ans = 0
for p in permute:
    # print(p)
    isCandi = True
    for q in quizes:
        # pdb.set_trace()
        cards = str(q[0])
        strikes = q[1]
        balls = q[2]
        s = count_s(p, cards)
        b = count_b(p,cards)
        # print("cards: ",cards,s,b)
        if s == strikes and b == balls:
            continue
        else:
            isCandi = False
            break
    if isCandi:
        ans += 1
print(ans)

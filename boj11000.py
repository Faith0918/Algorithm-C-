# boj 11000 강의실 배정
# start 3:55 finish 4:09

import heapq
from collections import defaultdict
n = int(input())
h = []
d = defaultdict(int)
for i in range(n):
    l = list(map(int,input().split()))
    d[l[0]]+=1
    d[l[1]]-=1
l = sorted(d.items(), key=lambda x:(x[0],x[1]))
# print(l)
answer = 0
s = 0
for i in range(len(l)):
    s += l[i][1]
    answer = max(s, answer)
# answer = 0

print(answer)

from itertools import combinations
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
s, c, h = [], [], []
for i in range(n):
    a = list(map(int, input().split()))
    s.append(a)
    for j in range(n):
        if a[j] == 2: c.append([i, j])
        if a[j] == 1: h.append([i, j])
c = combinations(c, m)
result = 100000000
for k in c:
    min_result = 0
    for i, j in h:
        min_num = 100000000
        for x, y in k:
            min_num = min(min_num, abs(x - i) + abs(y - j))
        min_result += min_num
    result = min(result, min_result)
print(result)
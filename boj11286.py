import heapq
from sys import stdin

n = int(input())
heap = []
answer = []
for i in range(n):
    x = int(stdin.readline())
    if x == 0:
        a = 0
        
        if len(heap)>0:
            # answer.append(heapq.heappop(heap)[1])
            a = heapq.heappop(heap)[1]
        print(a)
    else:
        heapq.heappush(heap,(abs(x),x))
# print(answer)
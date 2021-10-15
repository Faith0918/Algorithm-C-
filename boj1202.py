# boj 1202 보석도둑
# start 4:10 finish 5:13
# 가방에 넣을 수 있는 모든 보석들을 가치가 높은 순으로 sorting
# 가장 가치가 높은 보석을 담는다.
import sys
import heapq
import copy
n, k=map(int,input().split())
jewels = []
bags = []
for i in range(n):
    m,v = map(int,sys.stdin.readline().split())
    heapq.heappush(jewels, (m,v))
for i in range(k):
    c = int(sys.stdin.readline())
    heapq.heappush(bags, c)
capable_gem = []
answer = 0
for _ in range(k):
    capacity = heapq.heappop(bags)

    while jewels and capacity>=jewels[0][0]:
        [weight, value] = heapq.heappop(jewels)
        heapq.heappush(capable_gem, -value)
    if capable_gem:
        answer -= heapq.heappop(capable_gem)
    elif not jewels:
        break

        
print(answer)
import heapq
import sys
import pdb
n, h, t = list(map(int,input().split()))
l = []
heap = []
minn = 2e9
for i in range(n):
    x = int(sys.stdin.readline())
    heapq.heappush(heap,(-x,x))
for i in range(t):
    # print(heap[0])
    a = list(heapq.heappop(heap))
    if a[1]<h:
        minn = i
        heapq.heappush(heap, tuple(a))
        break
    # pdb.set_trace()
    a[1] = max(a[1]//2,1)
    a[0] = -a[1]
    # print(a)
    heapq.heappush(heap,tuple(a))
answer = "YES"

height = heap[0][1]
if height>=h:
    answer = "NO"

if answer == "YES" and minn == 2e9:
    minn = t
print(answer)
if answer == "NO":
    print(height)
else:
    print(minn)

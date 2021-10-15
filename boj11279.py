import heapq
import sys
n = int(input())
# q = heapq()
max_heap = []
answer = []
for i in range(n):
    a = int(sys.stdin.readline())
    if a == 0:
        if len(max_heap)==0:
            print(0)
            # answer.append(0)
        else:
            result = heapq.heappop(max_heap)
            print(result[1])
            # answer.append(result[1])
    else:
        
        heapq.heappush(max_heap,(-a, a))
# for a in answer:
#     print(a)
import heapq
n = int(input())
heap = []
answer = []
for i in range(n):
    l = list(map(int,input().split()))
    if l[0]==0:
        if len(heap) ==0:
            # answer.append(-1)
            print(-1)
        else:
            # answer.append(heapq.heappop(heap)[1])
            print(heapq.heappop(heap)[1])
    else:
        for j in range(1,l[0]+1):
            heapq.heappush(heap, (-l[j],l[j]))
# for a in answer:
#     print(a)

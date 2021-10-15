# I n은 정수 n을 q에 삽입하는 연산
# D 1은 q에서 최댓값을 삭제하는 연산을 의미.
# D -1은 q에서 최솟값을 삭제하는 연산을 의미.
# 최소/최대가 2개 이상이면, 1 개만 삭제됨.
# q가 비어있는데 D연산이 들어오면 무시
import heapq
import sys
def delete(visited, heap):
    while heap and visited[heap[0][1]]==True:
        heapq.heappop(heap)
t = int(input())
for i in range(t):
    k = int(input())
    heap = []
    heap_large = []
    visited  = [False for _ in range(k)]
    for j in range(k):
        command = str(sys.stdin.readline()).split()
        c = command[0]
        c_n = int(command[1])
        if c == "I":
            heapq.heappush(heap, (c_n,j))
            heapq.heappush(heap_large, (-c_n,j))
        
        else:
            if c_n==-1:
                delete(visited, heap)
                if heap:
                    a = heapq.heappop(heap)
                    # print("delete smallest", a)
                    visited[a[1]] = True
                
            else:
                delete(visited, heap_large)
                if heap_large:
                    a = heapq.heappop(heap_large)
                    # print("delete largest", a)
                    visited[a[1]] = True
    delete(visited, heap)
    delete(visited, heap_large)
    if len(heap)==0:
        print("EMPTY")
    else:
        minimum = heapq.heappop(heap)[0]
        maximum = -heapq.heappop(heap_large)[0]
        print(maximum, minimum)

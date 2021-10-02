n, b = map(int, input().split())
visited = [False for _ in range(n)]
pointer = {}
for i in range(n):
    p = int(input())
    pointer[i] = p

p = 0 # pointed person
m = 0 # answer
flag = False # if goal is met
while True:
    if visited[p] == True:
        break
    else:
        if p == b:
            flag = True
            break
        else:
            visited[p] = True
            p = pointer[p]
            m+=1

if flag == False:
    print(-1)
else:
    print(m)
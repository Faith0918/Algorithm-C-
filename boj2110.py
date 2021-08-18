
n, c = map(int, input().split())
x = []
y = [0 for _ in range(c)]

for i in range(n):
    x.append(int(input()))
x.sort()
s = 1
e = x[-1]-x[0]
rst = 0
while s <= e:
    m = (s+e)//2
    old = x[0]
    cnt = 1

    for i in range(1, n):
        if x[i] >= old+m:
            cnt +=1
            old = x[i]
    if cnt >=c:
        s = m + 1
        rst = m
    else:
        e = m-1

print(rst)

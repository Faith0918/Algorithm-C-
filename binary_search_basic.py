import bisect

n, x = map(int, input().split())

data = list(map(int, input().split()))

a = bisect.bisect_left(data, x)
b = bisect.bisect_right(data,x)
ans = a-b
if ans<=0:
    ans = -1
print(ans)


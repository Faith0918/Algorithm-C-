def search(a, start, end):
    if start<=end:
        mid = int((end+start)//2)
        if mid<a[mid]:
            return search(a, start, mid-1)
        elif mid == a[mid]:
            return mid
        else:
            return search(a, mid+1, end)
    else:
        return None

n = int(input())
a = list(map(int, input().split()))
print(type(n-1))
print(type(a))
ans = search(a, 0, n-1)
if ans == None:
    print(-1)
else:
    print(ans)
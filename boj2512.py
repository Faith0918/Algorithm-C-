n = int(input())
a = list(map(int, input().split()))
b = int(input())

a = sorted(a, reverse= True)
def checking(highst_m):
    hap = sum(highst_m if highst_m < m else m for m in a)
    return hap

l, r = b // n, max(a)
answer = 0
while l<=r:
    mid = (l+r)//2
    temp = checking(mid)
    if checking(mid)>b:
        r = mid-1
    else:
        answer = max(answer, mid)
        l = mid+1
print(answer)

a = [1]
b = [0]
n = int(input())
for i in range(0,n):
    a.append(b[i])
    b.append(a[i]+b[i])

ans = str(a[n])+" "+str(b[n])
print(ans)
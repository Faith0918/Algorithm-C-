f = [1,1,2,4]
for i in range(4, 70):
    f.append(f[i-1]+f[i-2]+f[i-3]+f[i-4])


t = int(input())
for t_ in range(t):
    n = int(input())
    print(f[n])
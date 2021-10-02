from collections import deque

t = int(input())
n = 10000
primeNumbers = []
a = [False,False] + [True]*(n-1)
for i in range(2,n+1):
    if a[i]:
        primeNumbers.append(i)
        for j in range(2*i, n+1,i):
            a[j] = False
# print(primeNumbers)

def isPrime(num):
    if num in primeNumbers:
        return True
    else:
        return False

for t_ in range(t):
    visited = []
    s, e = map(int, input().split())
    q = deque()
    q.append([s,0])
    ans = 0
    flag = False
    visited.append(s)
    while q:
        cur = q.popleft()
        if cur[0] == e:
            ans = cur[1]
            flag = True
            break
        cur_s = str(cur[0])
        for i in range(4):
            for j in range(10):
                new_s = cur_s
                new_s = "".join((new_s[:i],str(j),new_s[i+1:]))
                new_n = int(new_s)
                if new_s != cur_s and isPrime(new_n) and new_n not in visited and new_n>1000:
                    q.append([new_n, cur[1]+1])
                    visited.append(new_n)
    if flag == True:
        print(ans)
    else:
        print('Impossible')
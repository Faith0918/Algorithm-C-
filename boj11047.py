import sys
N,K = map(int, input().split())

coins = []
for i in range(N):
    coins.append(int(input()))

coins.sort(reverse=True)
idx = 0
ans = 0
while K>0:
    # print("while! K : ",K)
    if K<coins[idx]:
        idx+=1
    else:
        ans += int(K/coins[idx])
        K = K % coins[idx]
print(ans)
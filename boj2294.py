n, k = map(int, input().split())
coins = []
dp = [int(1e18) for i in range(k+1)]
dp[0] = 0
for i in range(n):
    coins.append(int(input()))

for i in range(0,k+1):
    for c in coins:
        if i+c < k+1 and dp[i]<int(1e18):
            dp[i+c] = min(dp[i+c], dp[i]+1)

if dp[k] ==int(1e18):
    print(-1)
else:
    print(dp[k])
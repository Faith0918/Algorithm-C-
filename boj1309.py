dp = [1,1]
mod = 9901
n = int(input())
for i in range(2,n+2):
    dp.append((dp[i-1]*2 + dp[i-2])%mod)
print(dp[n+1])
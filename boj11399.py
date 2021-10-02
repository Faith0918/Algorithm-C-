import sys

N = int(input())
times = []
times = list(map(int, input().split()))
# print(times)
times = sorted(times)
ans = 0
num_ppl = len(times)
for idx, time in enumerate(times):
    ans+=(num_ppl-idx)*time
print(ans)
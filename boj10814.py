# 이분 탐색을 사용할지 hash 탐색을 사용할지 시간복잡도를 미리 계산할 것.
n_cards = int(input())
cards = set(list(map(int, input().split())))
n_check = int(input())
checks = list(map(int, input().split()))
ans = ""
for i in checks:
    if i in cards:
        ans = ans + "1 "
    else:
        ans = ans + "0 "
print(ans)

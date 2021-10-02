n = int(input())
a = [1 for _ in range(n)]
s = list(map(int, input().split()))
# print(s)
for i, size in enumerate(s):
    # print("i : ", i,"size : ", size)
    for j in range(i):
        # print("j : ",j)
        if s[i] > s[j]:
            # print("i :",s[i], "j", s[j])
            a[i] = max(a[i],a[j] + 1)

# print(a)
print(max(a))
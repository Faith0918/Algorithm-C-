k, n = map(int, input().split())
cables = []
for i in range(k):
    cables.append(int(input()))
cables.sort()
def get_cables(l):
    s = 0
    for cable in cables:
        s += cable//l
    return s
start = 1
end = cables[-1]
ans = 0
# 꼭꼭 경계값을 확인하자(부등호 등)
while start<=end:
    middle = (start+end)//2
    
    candi = get_cables(middle)
    # print(start, middle, end, candi)
    if candi==n:
        ans = max(ans, middle)
        start = middle + 1
    elif candi<n:
        end = middle - 1
        # print("here", end)
    else:
        start = middle + 1
        ans = max(ans, middle)
print(ans)
    

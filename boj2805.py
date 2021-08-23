n, m = map(int, input().split())
trees = list(map(int, input().split()))
def binary_search(x):
    start = 0
    end = n-1
    while start<=end:
        mid = (start+end)//2
        if trees[mid] == x:
            return mid
        elif trees[mid]>x:
            end = mid-1
        else:
            start = mid+1
    return start
def cut_tree_length(h):
    s = 0
    idx = binary_search(h)
    for i in range(idx, n):
        s += trees[i]-h
    return s



trees.sort()
# print(trees)
start = 0
end = trees[-1]
ans = 0
while start <= end:
    mid = (start+end)//2
    # print(start, mid, end)
    candi = cut_tree_length(mid)
    # print("tree: ", candi)
    if candi==m:
        ans = mid
        break
    elif candi<m:
        end = mid - 1
    else:
        ans = max(mid, ans)
        start = mid + 1
print(ans)

def binary_search(target,data):
    start = 0
    end = len(data) - 1
    res = -1
    while start <= end :
        mid = (start + end) // 2
        if data[mid] < target:
            res = mid
            start = mid + 1
        else:
            end = mid - 1
    return res

test_case = int(input())
 
for _ in range(test_case):
    n, m = map(int, input().split())
    n_arr = list(map(int, input().split()))
    m_arr = list(map(int, input().split()))
    count = 0
    n_arr.sort()
    m_arr.sort()
 
    for i in n_arr:
        count += binary_search(i,m_arr) + 1
 
    print(count)

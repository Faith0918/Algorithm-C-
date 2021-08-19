def binary_search(target,data):
    start = 0
    end = len(data) - 1
    res = -1
    while start <= end :
        mid = (start + end) // 2
        if data[mid] ==  target:
            res = 1
            break
        # print("mid : ", mid, data[mid], "res : ", res, "s : ", start, "e : ", end)
        if data[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return res

test_case = int(input())
 
for _ in range(test_case):
    n = int(input())
    list_1 = list(map(int, input().split()))
    list_1.sort()
    # print(list_1)
    m = int(input())
    list_2 = list(map(int, input().split()))
    for i in list_2:
        # print("i :", i, binary_search(i, list_1))
        if binary_search(i, list_1) == -1:
            print(0)
        else:
            print(1)

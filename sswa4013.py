from collections import deque
T = int(input())
for test_case in range(1, T + 1):
    k = int(input())
    gears = []
    for i in range(4):
        gears.append(deque(map(int, input().split())))
        # input()
	# gears = [list(map(int, input().split())) for _ in range(4)]
    # print(gears)
    answer = 0
    def rotate(idx, d):
        global gears
        gears[idx].rotate(d)
    for i in range(k):
        n, d = map(int, input().split())
        n=n-1
        # print("move ", n, d)
        q = deque()
        q.append([n, d, -1])
        q.append([n,d,1])
        l = []
        l.append([n,d])
        while q:
            c = q.popleft()
            c_i = c[0]
            c_d = c[1]
            c_g_d = c[2]
            n_i = c_i + c_g_d
            if 0<=n_i<4:
                if c_g_d == -1: #left
                    if gears[n_i][2] != gears[c_i][6]:
                        q.append([n_i, -c_d, c_g_d])
                        l.append([n_i, -c_d])
                else:
                    if gears[n_i][6] != gears[c_i][2]:
                        q.append([n_i, -c_d, c_g_d])
                        l.append([n_i, -c_d])
        # print("moving gears",l)
        for g in l:
            idx = g[0]
            d = g[1]
            rotate(idx, d)
            # print("rotated!")
    for i in range(4):
        answer += pow(2,i)*gears[i][0]
    print('#%d'%test_case,answer)

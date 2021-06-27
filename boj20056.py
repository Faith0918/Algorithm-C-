# 주의
# 구현 문제도 알고리즘 시간 복잡도를 계산하자.

def initialize_map():
    return [[[] for _ in range(n)] for _ in range(n)]

def move_fireball():
    global mapp, fireballs, n
    new_fireballs = initialize_map()
    for r in range(n):
        for c in range(n):
            f_l = fireballs[r][c]
            for f in f_l:
                n_r = r + dr[f[2]] * f[1]
                n_c = c + dc[f[2]] * f[1]
                if n_r >= n:
                    n_r = n_r % n
                elif n_r <0:
                    n_r = (n_r + (n * 1000)) %n
                if n_c >= n:
                    n_c = n_c % n
                elif n_c < 0:
                    n_c = (n_c + (n * 1000)) %n
                new_fireballs[n_r][n_c].append(f)
    fireballs = new_fireballs
    

def get_fireballs(r,c):
    global fireballs
    rst = {}
    for i,fireball in enumerate(fireballs):
        if fireball[0] == r and fireball[1]==c:
            rst[i] = fireball
    return rst

def split_fireball():
    global mapp, fireballs
    new_fireballs = initialize_map()
    for r in range(n):
        for c in range(n):
            if len(fireballs[r][c]) > 1:
                fires_list = fireballs[r][c]
                new_mass = 0
                new_speed = 0
                new_dir = 0
                even_flag = False
                for f in fires_list:
                    new_mass += f[0]
                    new_speed += f[1]
                    new_dir += f[2]%2
                if new_mass//5 == 0:
                    continue
                if new_dir == 0 or new_dir == len(fires_list):
                    for i in range(0,8,2):
                        new_fireballs[r][c].append([new_mass//5 , new_speed//len(fires_list), i])
                else:
                    for i in range(1,8,2):
                        new_fireballs[r][c].append([new_mass//5 , new_speed//len(fires_list), i])
            elif len(fireballs[r][c]) == 1:
                new_fireballs[r][c].append(fireballs[r][c][0])
    fireballs = new_fireballs




dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]
n, m, k = map(int, input().split())
fireballs = [[[] for _ in range(n)] for _ in range(n)]
mapp = []
for i in range(m):
    r, c, m, s, d = map(int, input().split())
    fireballs[r-1][c-1].append([m,s,d])

for i in range(k):
    move_fireball()
    split_fireball()

ans = 0
for r in range(n):
    for c in range(n):
        for f in fireballs[r][c]:
            ans += f[0]
print(ans)
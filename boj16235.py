# boj 16235 start 4:51 finished 6:09 (1h18m)
# K년이 지난 후 상도의 땅에 살아있는 나무의 개수를 구한다.
# 1) 봄에 나무는 자신의 나이만큼 양분을 먹는다.
# 1.1) 만약 자신의 나이만큼 양분을 먹을 수 없으면 나무는 양분을 먹지 못하고 죽는다.
# 2) 여름에는 봄에 죽은 나무가 양분으로 변한다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
# 3) 가을에는 나무가 번식한다. 
# 3.1) 번식하는 나무는 나이가 5의 배수여야한다.
# 3.2) 번식하는 나무 주위 8칸에 나이가 1인 나무가 생긴다.
# 4) 겨울에는 땅에 양분을 추가한다. 
# 나무, 밭의 양분을 board 형식으로 저장하자.
# 실수 : x, y 가 바뀌어서 입력 받을 때 주의

from collections import defaultdict
def grow_trees():
    global trees, field
    dead_trees = defaultdict(list)
    for loc, ages in trees.items():
        r = loc[0]
        c = loc[1]
        total_age = 0
        ages.sort()
        for i, age in enumerate(ages):
            if field[r][c]<age:
                dead_trees[loc].append(i)
                # trees[loc] = trees[loc][:i]
                break
            else:
                field[r][c] -=age
                trees[loc][i]+=1
    return dead_trees
def decompose_dead_trees(dead_trees):
    global trees, field
    for loc, i in dead_trees.items():
        i = i[0]
        r = loc[0]
        c = loc[1]
        ages = trees[loc][i:]
        for age in ages:
            field[r][c] += (age//2)
        trees[loc] = trees[loc][:i]
def reproduce_trees():
    global trees,n
    baby_trees = defaultdict(list)
    dr = [0,0,1,1,1,-1,-1,-1]
    dc = [1,-1,0,1,-1,0,1,-1]
    for loc, ages in trees.items():
        for age in ages:
            if age%5 == 0:
                r = loc[0]
                c = loc[1]
                for d in range(8):
                    nr = r+dr[d]
                    nc = c+dc[d]
                    if 0<=nr<n and 0<=nc<n :
                        baby_trees[(nr,nc)].append(1)
    for loc, ages in baby_trees.items():
        if loc in trees.keys():
            trees[loc] = trees[loc] + ages
        else:
            trees[loc] = ages
def fertilize():
    global field, A, n
    for r in range(n):
        for c in range(n):
            field[r][c] += A[c][r]
def age_trees():
    global trees
    for loc,ages in trees.items():
        for i, age in enumerate(ages):
            trees[loc][i] +=1

def count_trees():
    global trees
    ans = 0
    for loc, ages in trees.items():
        ans += len(ages)
    return ans

n,m,k = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(n)]
trees = defaultdict(list)
field = [[5 for _ in range(n)] for _ in range(n)]

for i in range(m):
    r, c, age = map(int,input().split())
    trees[(c-1,r-1)].append(age)
for i in range(k):
    dead_trees = grow_trees()
    decompose_dead_trees(dead_trees)
    reproduce_trees()
    fertilize()

ans = count_trees()
print(ans)

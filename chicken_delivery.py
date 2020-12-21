# 1) 집마다 치킨집과의 거리 맵을 만든다.
# 2) 치킨집 M개를 고른다.
# 3) 집마다 치킨거리를 구한다.
# 4) 도시의 치킨거리를 구한다.
# 5) 최소 도시 치킨거리를 업데이트한다.

def get_city_chicken_length(selected):
    # 도시의 치킨거리 계산
    ans = 0
    for h_idx in range(len(houses)):
        chicken_length = 101
        for s_idx in range(len(selected)):
            store_idx = selected[s_idx]
            if chicken_map[h_idx][store_idx] < chicken_length:
                chicken_length = chicken_map[h_idx][store_idx]
        ans += chicken_length
    return ans
    
def dfs(cnt, idx, selected):
    global m
    if cnt == m:
        global minn
        candi = get_city_chicken_length(selected)
        if candi<minn:
            minn = candi
        return
    else:
        for i in range(idx, len(stores)):
            selected.append(i)
            dfs(cnt+1, i, selected)
            del selected[len(selected)-1]

n,m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
houses = []
stores = []
minn = int(1e9)
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            # house
            houses.append((i,j))
        elif arr[i][j] == 2:
            # store
            stores.append((i,j))
chicken_map = []
if len(houses)==0:
    print(0)
    exit()

for h_idx in range(len(houses)):
    row = []
    for s_idx in range(len(stores)):
        row.append(abs(houses[h_idx][0]-stores[s_idx][0])+abs(houses[h_idx][1]-stores[s_idx][1]))
    chicken_map.append(row)

selected = []
dfs(0,0,selected)

print(minn)

    

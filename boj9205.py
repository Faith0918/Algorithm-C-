from collections import deque
def find_nearest(c, x,y):
    min_dist  = int(1e9)
    ans = -1
    for i,c_ in enumerate(c):
        if min_dist>dist(x,y,c_[0],c_[1]):
            ans = i
            min_dist = dist(x,y,c_[0],c_[1])
    return ans
def compare(a, b):
    global x,y
    return dist(x,y,a,b)

def dist(x,y,n_x,n_y):
    return abs(n_x-x) + abs(n_y-y)
n_t = int(input())
ans = []

for t in range(n_t):
    n_c = int(input())
    s_x, s_y = map(int, input().split())
    c = []
    for n in range(n_c):
        c_x, c_y = map(int, input().split())
        c.append([c_x, c_y])
    e_x, e_y = map(int, input().split())
    c.append([e_x,e_y])

    is_sad = True
    q = deque()
    q.append([s_x,s_y,20])
    while len(q)>0:
        # print("while!",q)
        cur_loc = q.popleft()
        x = cur_loc[0]
        y = cur_loc[1]
        beer = cur_loc[2]
        if x == e_x and y == e_y:
            is_sad = False
            break
        # print("C  : ",c)
        for n_c in c:
            n_x, n_y = n_c[0], n_c[1]
            d = dist(x,y,n_x,n_y)
            # print("hh:",beer - (d/50))
            if beer - (d/50)>=0:
                n_b = beer - d//50
                if d%50>0:
                    n_b -= 1
                q.append([n_x,n_y,min(n_b+20,20)])
                c.remove(n_c)
                

    

    if is_sad == False:
        ans.append("happy")
    else:
        ans.append("sad")
for a in ans:
    print(a)
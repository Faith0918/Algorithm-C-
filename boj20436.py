def distance(p1, p2):
    return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])

def dfs(count, c_l, c_r, candi):
    global min_n
    if count == len(s):
        if candi<min_n:
            min_n = candi
        return
    else:
        goal = d[s[count]]
        
        cur_l = d[c_l]
        cur_r = d[c_r]
        # left hand
        if s[count] in left_keyboard:
            dfs(count+1, s[count], c_r, candi + distance(cur_l, goal)+1)
        # right hand
        else:
            dfs(count+1, c_l, s[count], candi + distance(cur_r, goal)+1)

left_right = str(input())
l, r = left_right.split()
s = str(input())
d = {}
keyboard = ['qwertyuiop','asdfghjkl','zxcvbnm']
left_keyboard = ['q','w','e','r','t','a','s','d','f','g','z','x','c','v']
for r_, row in enumerate(keyboard):
    for c_, cha in enumerate(row):
        d[cha] = [r_,c_]

min_n = int(1e9)

dfs(0, l, r, 0)
print(min_n)
def in_group(group, index):
    return index in group.values()
def switch_seat(index):
    global group1
    global group2
    total = group1.copy()
    total.update(group2)
    char_l = ''
    char_r = ''
    for k, v in total.items():
        if v == index:
            char_l = k
        if v == index + 1:
            char_r = k
    group1[char_l] = index+1
    group2[char_r] = index

n1,n2 = map(int, input().split())
g1 = str(input())
g2 = str(input())
t = int(input())
group1 = {}
group2 = {}
total_length = len(g1) + len(g2)
for i, c in enumerate(range(len(g1))):
    group1[g1[c]] = len(g1)-i-1
for i, c in enumerate(range(len(g2))):
    group2[g2[c]] = i+len(g1)

# print(group1, group2)
for t_ in range(t):
    i = 0
    while i<total_length-1:
        if in_group(group1, i) and in_group(group2, i+1):
            switch_seat(i)
            i+=2
        else:
            i+=1
group1.update(group2)
l = []
ans = ''
for key, value in group1.items():
    l.append([value, key])

l = sorted(l, key=lambda x: x[0])
for v in l:
    # print(v)
    ans = ans + str(v[1])
print(ans)
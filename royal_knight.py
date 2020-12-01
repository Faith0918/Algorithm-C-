#1. convert alphabet to number
#2. check every 8 positions

a = str(input())
c = int(ord(a[0]))-int(ord('a'))+1
r = int(a[1])
count = 0
dc = [2,2,-2,-2,1,1,-1,-1]
dr = [1,-1,1,-1,2,-2,2,-2]

for i in range(8):
    next_r = r+dr[i]
    next_c = c+dc[i]
    if next_r>=1 and next_r<=8 and next_c>=1 and next_c <=8:
        count+=1

print(count)
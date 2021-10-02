num = int(input())

right = 2**32
left = 0
# a = list(range(left, rig
inTheMiddle = False


while left<right:
    mid = (left+right)//2
    # print(left, right, mid)
    if num == mid**2:
        inTheMiddle = True
        print(mid)
        break
    elif num < mid**2:
        right = mid
        
    else:
        left = mid
    if mid == (left+right)//2:
        break

if inTheMiddle == False:
    # print(left, right, mid)
    if right**2 >=num:
        print(right)
    else:
        print(left)
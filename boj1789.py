num = int(input())

right = 2**32
left = 0
# print(right)
inTheMiddle = False
while left<right:
    mid = (left+right)//2
    if mid*(mid+1) == num * 2:
        inTheMiddle = True
        print(mid)
        break
    elif mid*(mid+1) < num * 2:
        left = mid
    else:
        right = mid
    if mid == (left+right)//2:
        break
if inTheMiddle == False:
    if num*2 >= right * (right+1):
        print(right)
    else:
        print(left)
a = str(input())
first = 0
second = 0
for idx in range(len(a)):
    if idx<len(a)/2:
        first += int(a[idx])
    else:
        second+= int(a[idx])

if first == second:
    print("LUCKY")
else:
    print("READY")
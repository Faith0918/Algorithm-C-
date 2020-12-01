H = int(input())
count = 0
for i in range(H+1):
    for j in range(60):
        for k in range(60):
            # Checking if a sentence has a letter
            if '3' in str(i)+str(j)+str(k):
                count += 1
print(count)
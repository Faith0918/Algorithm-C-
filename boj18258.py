# 6:46 start reading
# 7:11 finished solving
# 실수: 입력이 많을 때 sys.stdin.readline().rstrip()으로 입력을 받자.
from collections import deque
import sys
q = deque()
n = int(input())
for i in range(n):
    instr = sys.stdin.readline().rstrip().split()
    # pdb.set_trace()
    if len(instr)>1: # push
        q.append(int(instr[1]))
    else: # front, back, size, empty, pop
        instr = instr[0]
        if instr == 'front':
            if len(q)==0:
                print(-1)
            else:
                print(q[0])
        elif instr == 'size':
            print(len(q))
        elif instr == 'empty':
            if len(q) == 0:
                print(1)
            else:
                print(0)
        elif instr == 'pop':
            if len(q) == 0:
                print(-1)
            else:
                print(q.popleft())
        elif instr == 'back':
            if len(q) == 0:
                print(-1)
            else:
                print(q[-1])


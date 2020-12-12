import collections

# right, down, left, up
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

class Point:
    def __init__(self, r, c):
        self.r = r
        self.c = c

class Snake:
    def __init__(self):
        self.q = collections.deque([(1,1)])
        self.length = 1
        self.direction = 0
    def move(self):
        if self.move_head():
            #print("head moved to "+str(self.q[0][0])+" "+str(self.q[0][1]))
            if (check_apple(self.q[0])):
                # If there are apple
                arr[self.q[0][0]][self.q[0][1]] = -1
                self.length+=1
                #arr[self.q[0][0]][self.q[0][1]] = 0
            else:
                arr[self.q[0][0]][self.q[0][1]] = -1
                arr[self.q[len(self.q)-1][0]][self.q[len(self.q)-1][1]] = 0
                self.q.pop()
                
            return True
        else:
            return False
    def move_head(self):
        candi = (self.q[0][0]+dr[self.direction],self.q[0][1]+dc[self.direction])
        if (isPosssible(candi, self.q)):
            self.q.appendleft(candi)
            return True
        else:
            return False
        
def isPosssible(candi, q):
    if candi[0]>0 and candi[1] > 0 and candi[0]<=N and candi[1] <=N:
        if arr[candi[0]][candi[1]] != -1:
            return True
    else:
        return False

    return False
def check_apple(x):
    #print("check : " + str(x))
    if arr[x[0]][x[1]] == 1:
        return True
    else:
        return False        


def solve():
    # Initialize snake
    snake = Snake()
    # Initialize time
    answer = 0
    for t, d in time.items():
        #print("t : "+str(t))
        while answer < t:
            answer+=1
            # for i in range(len(arr)):
            #     print(arr[i])
            if (snake.move()):
                continue
            else:
                return answer
        if d=='D':
            snake.direction = (snake.direction + 1)%4
        else:
            snake.direction = (snake.direction - 1)%4
    while True:
        answer +=1
        if(snake.move()):
            continue
        else:
            return answer
    




N = int(input())
K = int(input())
# Initialize map
arr = [[0]*(N+1) for _ in range(N+1)]
arr[1][1] = -1
for i in range(K):
    a,b = map(int, input().split())
    arr[a][b] = 1
L = int(input())
time = {}
for i in range(L):
    X,C = input().split()
    time[int(X)] = str(C)

print(solve())


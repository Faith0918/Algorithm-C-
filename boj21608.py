n = int(input())
m = [[0]*n for _ in range(n)]
students = {}
dr = [0,0,1,-1]
dc = [1,-1,0,0]
def get_num_friends(r,c,eval=None):
    num = 0
    if eval == None:
        for d in range(4):
            n_r = r + dr[d]
            n_c = c + dc[d]
            if n_r >=0 and n_r<n and n_c>=0 and n_c<n:
                if m[n_r][n_c] in student[1:]:
                    num+=1
    else:
        s = m[r][c]
        for d in range(4):
            n_r = r + dr[d]
            n_c = c + dc[d]
            if n_r >=0 and n_r<n and n_c>=0 and n_c<n:
                if m[n_r][n_c] in students[s]:
                    num+=1
    return num
def get_num_blanks(r,c ):
    num = 0
    for d in range(4):
            n_r = r + dr[d]
            n_c = c + dc[d]
            if n_r >=0 and n_r<n and n_c>=0 and n_c<n:
                if m[n_r][n_c] == 0:
                    num+=1
    return num

def find_candi():
    seats = []
    for r in range(n):
        for c in range(n):
            if m[r][c] == 0:
                num_f = get_num_friends(r,c)
                num_b = get_num_blanks(r,c)
                seats.append([num_f, num_b, r, c])
    return seats

for i in range(n*n):
    # get input
    student = list(map(int, input().split()))
    # save student's friends in dictionary
    students[student[0]] = student[1:]
    # get all candidate seats and condition values
    candi = find_candi()
    # sort seats by conditions
    candi = sorted(candi, key = lambda x: (x[0],x[1],-1*x[2],-1*x[3]), reverse=True)
    # put student in the best seat
    m[candi[0][2]][candi[0][3]] = student[0]

    
ans = 0
board = [1,10,100,1000]
for r in range(n):
    for c in range(n):
        # evaluate scores
        score = get_num_friends(r,c,True)
        score = int(pow(10, score-1))
        ans+=score
print(ans)
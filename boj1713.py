# boj 1713 후보 추천하기
# start 3:15
# 1) 모든 사진틀은 비어있다.
# 2) 어떤 학생이 추천받으면, 추천 받은 학생은 사진이 반드시 올라간다.
# 3) 비어있는 틀이 없는 경우 
# 3-1) 현재 추천 회수가 가장 적은 학생의 사진을 삭제하고 그 자리에 새롭게 추천받은 학생 사진 게시
# 3-2) 두 명 이상일 경우 게시된 지 가장 오래된 사진 삭제
# 4) 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우 횟수만 증가
# 5) 사진틀 사진이 삭제되는 경우 해당 학생이 추천받은 회수는 0으로 바뀐다.
# 실수: 사진틀 길이가 아닌, 겹치는 것을 먼저 확인해야함.
# 틀렸을 때 반례 케이스를 꼼꼼이 따져보자.
from collections import defaultdict
import pdb
n = int(input())
num_r = int(input())
r_l = list(map(int,input().split()))
pictures = list()
# pdb.set_trace()
for t,r in enumerate(r_l):
    # pdb.set_trace()
    # print(pictures)
    is_on_list = False
    for i,pic in enumerate(pictures):
            if pic[0]==r:
                is_on_list = True
                pictures[i][1]+=1
    if len(pictures)>= n and is_on_list==False:
            # 정렬하고 가장 추천수가 적고, 오래된 것을 지운다.
            pictures = sorted(pictures, key=lambda x:(x[1],x[2]))
            del pictures[0]
            pictures.append([r,1,t])
    elif is_on_list==False:
        pictures.append([r,1,t])
    # print(pictures)
pictures = sorted(pictures, key=lambda x:(x[0]))
ans = ''
for i,p in enumerate(pictures):
    if i<len(pictures)-1:
        ans = ans + str(p[0])+' '
    else:
        ans = ans+str(p[0])
print(ans)
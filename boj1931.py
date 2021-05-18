import sys

N = int(input())

meetings = []
for i in range(N):
    start, end = map(int, input().split())
    meetings.append((start, end))

meetings = sorted(meetings, key=lambda meeting:(meeting[1], meeting[0]))
# print(meetings)
time_available = meetings[0][1]
ans = 1
for idx, meeting in enumerate(meetings):
    if idx>0:
        if meeting[0]>=time_available:
            # print(meeting)
            time_available = meeting[1]
            ans +=1
        
print(ans)
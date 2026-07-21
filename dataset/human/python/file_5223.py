from collections import deque
H, W = map(int, input().split())
k=[0]*200000
for i in range(W):
    ta,tb = map(int, input().split())
    if ta == 1:
        k[tb-1]+=1
    if tb == H:
        k[ta-1]+=1
s = 0
for i in range(len(k)):
    if k[i]>=2:s=1
if s ==1:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")

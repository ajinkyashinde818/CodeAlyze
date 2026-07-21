import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections

def judge(li):
    score = 0
    cnt = 0
    for i in range(len(li)):
        if li[i] == False:
            continue
        score += pc[i][1]
        score += pc[i][0]*(i+1)*(100)
        cnt += pc[i][0]
    return [cnt,score]
    
        
D,G = map(int,input().split())
pc = []
for i in range(D):
    p,c = map(int,input().split())
    pc.append([p,c])
ans = 100000000000000
for i in range(2**D):
    li = [False]*(D)
    for j in range(D):
        if (i>>j)&1:
            li[D-j-1] = True
    a = judge(li)
    j = D-1
    if a[1]<G:
        need = G-a[1]
        while True:
            if a[1]>=G:
                break
            if j == -1:
                break
            if li[j] == True:
                j-=1
                continue
            for k in range(pc[j][0]-1):
                a[1] += (j+1)*(100)
                a[0] += 1
                if a[1]>=G:
                    break
            j-=1
    if a[1]>=G:
        ans = min(ans,a[0])
print(ans)

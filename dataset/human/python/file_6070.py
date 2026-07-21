import numpy as np

N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

score=0
tmp=-1
for i in A:
    score+=B[i-1]
    if i==tmp+1:
        score+=C[tmp-1]
    tmp=i
print(score)

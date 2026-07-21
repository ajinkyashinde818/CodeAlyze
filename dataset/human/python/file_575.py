import sys
input = sys.stdin.readline
import numpy as np
N=int(input())
A=np.array([int(i) for i in input().split()])
B=np.abs(A)
if np.sum(np.where(A<0,1,0)) % 2 == 1 :
    print(np.sum(B)-np.min(B)*2)
else:
    print(np.sum(B))

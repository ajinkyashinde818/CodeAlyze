from sys import stdin
from collections import deque
q=deque()
K,N= list(map(int, (stdin.readline().strip().split())))
A=list(map(int, (stdin.readline().strip().split())))
max=A[1]-A[0]
home=0
home_B=0
place=0
kyori=0
for i in range(N-1):
    if max< A[i+1]-A[i]:
        max=A[i+1]-A[i]
        place=i
B=A[place]
C=A[place+1]-K
D=B-C
if A[-1]-A[0]>D:print(D)
else:print(A[-1]-A[0])

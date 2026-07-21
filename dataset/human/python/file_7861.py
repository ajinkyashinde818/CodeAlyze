import sys
input = sys.stdin.readline

N,K,S=map(int,input().split())

A=[]

for i in range(K):
    A.append(S)

if S!=10**9:
    for i in range(N-K):
        A.append(S+1)
else:
    for i in range(N-K):
        A.append(S-1)

print(*A)

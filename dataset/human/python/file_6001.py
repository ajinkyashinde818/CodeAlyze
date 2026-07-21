import sys
N=input()
A=[None]+map(int, sys.stdin.readline().split())
B=[None]+map(int, sys.stdin.readline().split())
C=[None]+map(int, sys.stdin.readline().split())

ans=0
prev=None
for a in A:
    if a is None: continue
    ans+=B[a]
    if prev is not None and prev+1==a:
        ans+=C[prev]
    prev=a

print ans

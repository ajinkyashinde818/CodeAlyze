import sys
K,N=map(int, sys.stdin.readline().split())
A=map(int, sys.stdin.readline().split())

L=[]
prev=None
for a in A:
    if prev is None:
        prev=a
    else:
        L.append(a-prev)
        prev=a
else:
    L.append(K-A[-1]+A[0])

print K-max(L)

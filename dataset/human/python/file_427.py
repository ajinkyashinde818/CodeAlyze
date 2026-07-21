"""
python3 main.py < input.txt
"""
import math
import itertools as it
import heapq
"""
A,B,T=map(int, input().split())
print(int(math.floor((T+0.5)/(A))*B))
"""
"""
N=int(input())
V=list(map(int, input().split()))
C=list(map(int, input().split()))
print(sum([V[i] - C[i] for i in range(N) if V[i] - C[i] > 0]))
"""
"""
N=int(input())
A=list(enumerate(map(int, input().split())))
l=list(A)
l.sort()

x=(-1, -1)
y=(-1, -1)

while l[0][1] != 0:
        l=list(map(lambda it: (it[0], it[1]%l[0][1]), l[1:]))
        (i, xi) = x
"""
N=int(input())
A=list(map(int, input().split()))
nNeg = len([1 for a in A if a < 0])
minAbs = min(A, key=lambda ai: abs(ai))
if nNeg%2 == 0:
        print(sum([abs(ai) for ai in A]))
else:
        print(-2*abs(minAbs) + sum([abs(ai) for ai in A]))

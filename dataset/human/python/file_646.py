import sys
def input():
    return sys.stdin.readline()[:-1]
N=int(input())
A=tuple(map(int,input().split()))
B=[abs(i) for i in A]
o=0
for i in A:
    if i<0:
        o+=1
if o%2==0:
    print(sum(B))
else:
    print(sum(B)-min(B)*2)

import sys
lines = sys.stdin.readlines()
N,M = map(int,(lines[0].split()))
seta,setb = set(),set()
for m in range(1,M+1):
    a,b = map(int,(lines[m].split()))
    if a == 1:
        seta.add(b)
    if b == N:
        setb.add(a)        
if seta & setb:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")

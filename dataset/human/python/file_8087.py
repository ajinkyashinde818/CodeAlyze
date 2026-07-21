import sys
def input(): return sys.stdin.readline().strip()
k,s=map(int,input().split())
c=0
for x in range(max(0,s-2*k),k+1):
    for y in range(max(0,s-x-k),min(k,s-x)+1):
        c += 1
print(c)

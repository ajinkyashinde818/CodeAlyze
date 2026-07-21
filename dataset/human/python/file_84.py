import sys
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

r,g,b,n = na()
ans=0
for i in range(n//r+1):
    a = n-r*i
    for j in range(a//g+1):
        if (a-g*j)%b == 0:
            ans+=1

print(ans)

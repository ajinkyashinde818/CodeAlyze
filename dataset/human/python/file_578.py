import sys
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()
c=0
for i in a:
    if i < 0:
        c+=1

b = [abs(i) for i in a]

if c%2 == 0:
    print(sum(b))
    exit()

b.sort()
print(sum(b)-2*b[0])

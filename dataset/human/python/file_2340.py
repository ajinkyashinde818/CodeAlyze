import itertools
import sys
sys.setrecursionlimit(10**9)
input = lambda: sys.stdin.readline().rstrip()
inpl = lambda: list(map(int,input().split()))

D, G = inpl()
G //= 100
pc = [inpl() for _ in range(D)]
p = [x[0] for x in pc]
c = [x[1]//100 for x in pc]
total = [(i+1)*p[i]+c[i] for i in range(D)]

ans = sum(p)
for complete in itertools.product(range(2),repeat=D):
    n = 0
    g = G
    for i in range(D):
        if complete[i]:
            g -= total[i]
            n += p[i]
    for i in range(D-1,-1,-1):
        if complete[i]:
            continue
        else:
            if g <= 0:
                break
            elif g > (p[i]-1)*(i+1):
                g -= (p[i]-1)*(i+1)
                n += p[i]-1
            else:
                n += g//(i+1) + int(bool(g%(i+1)))
                g = 0
                break
    if g <= 0 and n < ans:
        ans = n
print(ans)

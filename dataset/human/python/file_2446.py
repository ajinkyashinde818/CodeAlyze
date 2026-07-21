import math

D,G = map(int,input().split(" "))
G //= 100
p = []
c = []
for x in range(D):
    a,b = map(int,input().split(" "))
    p.append(a)
    c.append(b//100)

h = [sum(p)]

for x in range(2**D):
    o = [(x//(2**y))%2 for y in range(D)]
    if not(0 in o):
        continue
    g = sum([p[y]*(y+1)+c[y] for y in range(D) if o[y]])
    if g >= G:
        h.append(sum([p[y] for y in range(D) if o[y]]))
        continue
    s = max([y for y in range(D) if not(o[y])])
    if g + (s+1)*(p[s]-1) >= G:
        h.append(sum([p[y] for y in range(D) if o[y]])+math.ceil((G-g)/(s+1)))

print(min(h))

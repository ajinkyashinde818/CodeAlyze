import sys
from itertools import product

D, G = [int(i) for i in input().strip().split(' ')]
ps = []
cs = []
alls = []
vs = []
counter = 0
for line in sys.stdin:
    counter += 100
    p, c =[int(i) for i in line.strip().split(' ')]
    ps.append(p)
    cs.append(c)
    all = p * counter + c
    alls.append(all)
    vs.append(float(all)/p)

candidates = []
for x in  product([False, True], repeat=D):
    score = 0
    cnum = 0
    for count, bit in enumerate(x):
        if bit:
            score += alls[count]
            cnum += ps[count]
    if score >= G:
        candidates.append(cnum)
        continue
    for count, bit in enumerate(x[::-1]):
        if not bit:
            for xxx in range(ps[D-count-1]):
                score += (D-count) * 100
                cnum += 1
                if score >= G:
                    candidates.append(cnum)
                    break
print(min(candidates))

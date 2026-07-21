from itertools import product

d, g = map(int, input().split())
g //= 100

p = []
c = []
for _ in range(d):
    p_, c_ = map(int, input().split())
    p.append(p_)
    c.append(c_ // 100)

tmp_prbs = [0] * (2 ** d)
tmp_pts = [0] * (2 ** d)
for i, comp in enumerate(product([False, True], repeat=d)):
    tmp_pts[i] = sum((i+1)*p[i] + c[i] for i in range(d) if comp[i])
    tmp_prbs[i] = sum(p[i] for i in range(d) if comp[i])
    
    for j in reversed(range(d)):
        if tmp_pts[i] >= g:
            break
        if comp[j]:
            continue
        tmp_prbs[i] += min(p[j]-1, -((tmp_pts[i] - g) // (j+1)))
        tmp_pts[i] += min(p[j]-1, -((tmp_pts[i] - g) // (j+1))) * (j+1)
    
print(min(tmp_prb for tmp_pts, tmp_prb in zip(tmp_pts, tmp_prbs) if tmp_pts>=g))

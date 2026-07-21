d, g = map(int, input().split())

p = []
c = []

for i in range(d):
    pi, ci = map(int, input().split())
    p.append(pi)
    c.append(ci)

def two_list(d):
    if d == 1:
        return [[0],[1]]
    else:
        res = []
        prevlist = two_list(d-1)
        for l in prevlist:
            tmp = l + [0]
            res.append(tmp)
            tmp = l + [1]
            res.append(tmp)
        return res

s = []
for i in range(d):
    sump = 100 * (i+1) * p[i] + c[i]
    s.append(sump)

minp = sum(p)

for twolist in two_list(d):
    sumall = 0
    sumnum = 0
    for i in range(d):
        sumall += s[i] * twolist[i]
        sumnum += p[i] * twolist[i]
    if 0 in twolist:
        max0 = d - twolist[::-1].index(0)
    else:
        break
    if sumall >= g:
        minp = min(minp, sumnum)
    elif sumall < g and (g-sumall) < s[max0-1]:
        add = (g-sumall)//(100*max0)
        sumnum += add
        if (g-sumall)%(100*max0) != 0:
            sumnum += 1
        minp = min(minp, sumnum)

print(minp)

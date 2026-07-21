import math
d,g = map(int,input().split())
p = [0 for i in range(d)]
c = [0 for i in range(d)]
for i in range(d):
    p[i],c[i] = [int(j) for j in input().split()]

mn = 10**18
for i in range(2**d):
    ii = i
    ni = 0
    mh = -1
    pi = 0
    for j in range(d):
        if ii&1 == 1:
            pi += p[j]*(j+1)*100+c[j]
            ni += p[j]
        else:
            mh = j
        ii >>= 1
    res = g-pi
    if res > (p[mh]-1)*(mh+1)*100:
        continue
    elif 0 < res:
        ni += math.ceil(res/((mh+1)*100))
    if mn > ni:
        mn = ni

print(mn)

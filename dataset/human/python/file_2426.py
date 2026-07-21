import math

d, g = [int(i) for i in input().split(" ")]
p = [0] * (d + 1)
c = [0] * (d + 1)

for i in range(1, d + 1):
    p[i], c[i] = [int(i) for i in input().split(" ")]

p_min = 10000

def cp(a):
    global p_min
    r = g - sum([(p[i] * 100 * i + c[i]) * a[i] for i in range(1, d + 1)])
    ps = sum([p[i] * a[i] for i in range(1, d + 1)])
    if r <= 0:
        if ps < p_min:
            p_min = ps
        return
    
    for i in reversed(range(1, d + 1)):
        if a[i] == 0:
            s = (p[i] - 1) * 100 * i
            if r - s <= 0:
                ps += math.ceil(r / (100 * i))
                if ps < p_min:
                    p_min = ps
                break
            else:
                ps += p[i] - 1
                r -= s

def trav(a):
    global d
    if len(a) == d + 1:
        cp(a)
    else:
        trav(a + [0])
        trav(a + [1])

trav([0])

print(p_min)

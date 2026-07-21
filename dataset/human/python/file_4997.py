import sys
f = sys.stdin

def get_v(c):
    v = 0
    for ci in c:
        v *= 10
        v += ci
    return v

c = (1,4,1,4,1,2,1,2)

for line in f:
    p = list(map(int, line.split()))
    min_waiting = None
    min_c = None
    for i in range(len(c)):
        ci = c[i:] +c[:i]
        waiting = sum(max(0, p[i] - ci[i]) for i in range(len(c)))
        if min_waiting == None or min_waiting > waiting:
            min_waiting = waiting
            min_c = ci
        elif min_waiting == waiting and get_v(min_c) > get_v(ci):
            min_c = ci
    print(*min_c)

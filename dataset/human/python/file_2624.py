D, G = map(int, input().split())
pc = [[i + 1] + [int(x) for x in input().split()] for i in range(D)]

import math
m = {}
def f(cur, n, left):
    if left <= 0:
        return n
    def g(cur, n, left):
        if cur in m: return m[cur]
        r = m[cur] = f(cur, n, left)
        return r
    ret = 10**9
    for x in pc:
        i, p, c = x
        if (1 << i) & cur: continue
        ip = i*100*p
        if ip > left:
            h = math.ceil(left / (i*100))
            ret = min(ret, n + h)
        else:
            if n + p >= ret: continue
            h = g(cur | (1 << i), n + p, left - ip - c)
            ret = min(ret, h)
    return ret

print(f(0, 0, G))

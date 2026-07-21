def encode(n):
    ns = []
    mcxi = ['m','c','x','i']
    v = 1000
    for i in range(4):
        m = 0
        while n >= v:
            n -= v
            m += 1
        v = int(v/10)
        if m > 0:
            ns.append(str(m)+mcxi[i])
    return ''.join(ns).replace('1','')

def decode(s):
    coe = 1
    n = 0
    for c in s:
        if c in map(str, range(2,10)):
            coe = int(c)
        elif c == 'm':
            n += coe * 1000
            coe = 1
        elif c == 'c':
            n += coe * 100
            coe = 1
        elif c == 'x':
            n += coe * 10
            coe = 1
        elif c == 'i':
            n += coe * 1
            coe = 1
    return n

n = int(input())
for i in range(n):
    ns = input().split()
    s = decode(ns[0]) + decode(ns[1])
    print(encode(s))

import sys
m = [4,1,4,1,2,1,2,1]

for l in sys.stdin:
    l = list(map(int, l.rstrip().split()))
    a = []
    for i in range(0, 8):
        _m = [m[j%8] for j in range(i, i+8)]
        n = 0
        for n1, n2 in zip(l, _m):
            n += max(0, n1-n2)
        a.append((n, "".join(map(str, _m))))
    print(" ".join(sorted(a)[0][1]))

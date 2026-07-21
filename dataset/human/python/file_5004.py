import sys

d = [[1, 2, 1, 2, 1, 4, 1, 4],
     [1, 2, 1, 4, 1, 4, 1, 2],
     [1, 4, 1, 2, 1, 2, 1, 4],
     [1, 4, 1, 4, 1, 2, 1, 2],
     [2, 1, 2, 1, 4, 1, 4, 1],
     [2, 1, 4, 1, 4, 1, 2, 1],
     [4, 1, 2, 1, 2, 1, 4, 1],
     [4, 1, 4, 1, 2, 1, 2, 1]]

for s in sys.stdin:
    c = map(int, s.split())
    r = 0
    min = 0x7fffffff
    for i in range(8):
        rr = 0
        for j in range(8):
            if c[j] > d[i][j]:
                rr += c[j] - d[i][j]
        if rr < min:
            min = rr
            r = i
    print ' '.join(map(str, d[r]))
    a = 1

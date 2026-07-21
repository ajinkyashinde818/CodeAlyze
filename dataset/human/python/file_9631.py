import sys

n, k = map(int, input().split())
a = list(map(int, input().split()))
d = {}
d2 = {}
d3 = {}
loopc = 0
for i in range(1, n + 1):
    d[i] = a[i - 1]


b = d[1]
d2[b] = 1
d3[i] = b
amari = 0
if k >= 2:
    if n >= k:
        for i in range(2, k + 1):
            if b in d:
                b = d[b]
        print(b)
    else:
        for i in range(2, n + 1):
            if b in d:
                b = d[b]
                if b not in d2:
                    d2[b] = i
                    d3[i] = b
                elif b in d2:
                    loopc = i - d2[b]
            else:
                print(b)
                sys.exit()

        amari = k - n
        amari = amari % loopc
        for i in range(amari):
            b = d[b]
        print(b)
else:
    print(b)

import sys
input = sys.stdin.readline

n = int(input())
fs = [input().split() for i in range(n)]
check = "mcxi"

for f2 in fs:
    v = [0, 0, 0, 0]
    for f in f2:
        for i in range(len(f)):
            for c in range(4):
                if check[c] == f[i]:
                    if i==0:
                        tmp = 1
                    else:
                        tmp = 1 if f[i-1] in check else int(f[i-1])
                    v[c] += tmp
                    break
    for i in range(3, 0, -1):
        if v[i] > 9:
            v[i] -= 10
            v[i-1] += 1
    for i in range(4):
        if v[i] > 0:
            print(check[i] if v[i] == 1 else str(v[i])+check[i], end="")
    print()

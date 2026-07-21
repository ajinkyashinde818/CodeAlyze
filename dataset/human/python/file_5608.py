import sys

S = sys.stdin.readline().strip()

N = len(S)

pl = 0
pr = N

res = 0

while pl < pr:
    cnt = 0

    while pl < N and S[pl] == 'x':
        cnt += 1
        pl += 1

    while 0 < pr and S[pr - 1] == 'x':
        cnt -= 1
        pr -= 1

    res += abs(cnt)

    if 0 < pr and pl < N and S[pl] != S[pr - 1]:
        print(-1)
        sys.exit()

    pl += 1
    pr -= 1

print(res)

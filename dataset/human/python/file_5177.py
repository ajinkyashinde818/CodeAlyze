import bisect

N, M = map(int,input().split())
AB = []
for m in range(M):
    a,b = map(int,input().split())
    AB.append((a,b))

AB = sorted(AB)

first = []
for a,b in AB:
    if a == 1:
        first.append(b)
    else:
        break

AB = sorted(AB, key=lambda x:x[1], reverse=True)
sec = []
for a,b in AB:
    if b == N:
        sec.append(a)
    else:
        break

if len(sec) >= 100:
    for f in first:
        ind = bisect.bisect_left(sec, f, 0, len(sec))
        if sec[ind] == f:
            print('POSSIBLE')
            exit()
else:
    for f in first:
        if f in sec:
            print('POSSIBLE')
            exit()

print('IMPOSSIBLE')

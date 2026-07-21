from collections import deque

n, k = map(int, input().split())
a = tuple(map(int, input().split()))

tere = {}
for i in range(n):
    tere[i+1] = a[i]

mati = deque([1])
mark = set([1])
tugi = 1
for i in range(1, k+1):
    if tere[tugi] not in mark:
        mati.append(tere[tugi])
        mark.add(tere[tugi])
    else:
        mati.append(tere[tugi])
        mark.add(tere[tugi])
        break
    tugi = tere[tugi]
else:
    print(tugi)
    exit()

mati = list(mati)
cnta = len(mati)-1
i = mati.index(mati[-1]) + 1
cntroop = cnta - i + 1
roop = mati[i:]

print(roop[(k-cnta)%cntroop-1])

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

sa = set(a)
sb = set(b)

count = [0] * (n + 1)
counta = [0] * (n + 1)
countb = [0] * (n + 1)

for v in a:
    count[v] += 1
    counta[v] += 1
for v in b:
    count[v] += 1
    countb[v] += 1

for v in count:
    if v > n:
        print('No')
        exit()

outA = dict()
for v in a:
    outA[v] = []

import heapq
q = []
for v in range(n + 1):
    if count[v]:
        heapq.heappush(q,(-count[v],v))
    
while q[0][0] < 0:
    c, v = heapq.heappop(q)
    if count[v] + c:
        heapq.heappush(q,(-count[v],v))
        continue
    if counta[v]:
        for v2 in sb:
            if v2 != v:
                break
        else:
            print('No')
            exit()
        outA[v].append(v2)
        count[v] -= 1
        count[v2] -= 1
        counta[v] -= 1
        countb[v2] -= 1
        if counta[v] == 0:
            sa.remove(v)
        if countb[v2] == 0:
            sb.remove(v2)
    else:
        for v2 in sa:
            if v2 != v:
                break
        else:
            print('No')
            exit()
        outA[v2].append(v)
        count[v] -= 1
        count[v2] -= 1
        counta[v2] -= 1
        countb[v] -= 1
        if counta[v2] == 0:
            sa.remove(v2)
        if countb[v] == 0:
            sb.remove(v)
    if count[v]:
        heapq.heappush(q, (-count[v], v))

out = []
for v in a:
    out.append(outA[v].pop())
print('Yes')
print(' '.join(map(str,out)))

from collections import deque
import sys

N = int(input())
As = list(map(int, input().split()))
Bs = list(map(int, input().split()))

isEssentials = [False] * 51
for k in reversed(range(1, 52)):
    adjL = [set() for _ in range(51)]
    for v in range(1, 51):
        for t in range(1, v+1):
            if t < k or isEssentials[t]:
                adjL[v].add(v%t)
        adjL[v] = list(adjL[v])

    for A, B in zip(As, Bs):
        isOK = False
        useds = [False] * 51
        Q = deque([A])
        while Q:
            vNow = Q.popleft()
            if vNow == B:
                isOK = True
                break
            useds[vNow] = True
            for v2 in adjL[vNow]:
                if not useds[v2]:
                    Q.append(v2)
        if not isOK:
            if k == 51:
                print(-1)
                sys.exit()
            isEssentials[k] = True
            break

ans = sum([2**k for k in range(1, 51) if isEssentials[k]])
print(ans)

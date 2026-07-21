N, M = map(int, input().split())

A = [""] * N
for _ in range(N):
    A[_] = input()

B = [""] * M
for _ in range(M):
    B[_] = input()

import sys
ans = True

for nvi in range(N-M+1):
    for nhi in range(N-M+1):
        ok = True

        for vi in range(M):
            for hi in range(M):
                if A[nvi+vi][nhi+hi] == B[vi][hi]:
                    pass
                else:
                    ok = False
                    break
        
        if ok:
            print("Yes")
            sys.exit()

print("No")

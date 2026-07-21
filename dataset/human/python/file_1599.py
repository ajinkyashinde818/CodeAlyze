import sys
N, M = map(int, input().split())
aLst = list(input() for i in range(N))
bLst = list(input() for i in range(M))
ans = False
cnt = 0
for j in range(N - M + 1):
    for k in range(N - M + 1):
        if aLst[j][k:k + M] == bLst[0]:
            cnt += 1
            for l in range(1, M):
                if aLst[j + l][k:k + M] == bLst[l]:
                    cnt += 1
                else:
                    break

            if cnt == M:
                print('Yes')
                sys.exit()
            cnt = 0

print('No')

from collections import Counter
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

A_cnt = Counter(A)
B_cnt = Counter(B)
for i in range(1,N+1):
    if N < A_cnt[i]+B_cnt[i]:
        print("No")
        break
else:
    print("Yes")
    cnt = 0
    indexes = {}
    alreadychecked = set()
    for i in range(N):
        if A[i] not in alreadychecked:
            indexes[A[i]] = i
            alreadychecked.add(A[i])
    zure = 0
    alreadychecked = set()
    for i in range(N-1,-1,-1):
        if B[i] not in alreadychecked:
            if B[i] in indexes and indexes[B[i]] <= i:
                zure = max(zure,i-indexes[B[i]]+1)
                alreadychecked.add(B[i])

    print(*B[zure:],*B[:zure])

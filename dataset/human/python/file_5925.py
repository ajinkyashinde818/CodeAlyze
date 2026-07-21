def inpl():
    return list(map(int, input().split()))


N = int(input())
A = inpl()
B = inpl()
C = inpl()

A = [(i, A[i]) for i in range(N)]
A.sort()

ans = sum(B)
for a, na in zip(A, A[1:]):
    if a[1] + 1 == na[1]:
        ans += C[a[1] - 1]

print(ans)

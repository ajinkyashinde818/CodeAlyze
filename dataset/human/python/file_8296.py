def solve():
    N, *A = map(int, open(0).read().split())

    K = N * (N + 1) // 2
    if sum(A) % K != 0:
        return False

    t = sum(A) // K
    cnt = 0
    for a, b in zip(A, A[1:] + [A[0]]):
        d = t + a - b
        if d % N or d < 0:
            return False
        cnt += d // N

    return (t == cnt)

if solve():
    print("YES")
else:
    print("NO")

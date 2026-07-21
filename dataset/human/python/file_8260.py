N = int(input())
A = list(map(int, input().split()))
S = sum(A)


def solve():
    n = (N + 1) * N // 2
    if S % n != 0:
        return False
    c = S // n
    cc = 0
    for i in range(N):
        j = (i + 1) % N
        delta = A[j] - A[i]
        if (c - delta) % N != 0:
            return False
        ci = (c - delta) // N
        if ci < 0:
            return False
        cc += ci
    assert(c == cc)


    return True

if solve():
    print('YES')
else:
    print('NO')

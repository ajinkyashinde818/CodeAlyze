def solve(n, A):
    total = sum(A)
    x = A[0]
    ret = abs(2 * x - total)
    for i in range(1, n - 1):
        x += A[i]
        y = total - x
        if abs(x - y) < ret:
            ret = abs(x - y)
    return ret

_n = int(input())
_A = list(map(int, input().split()))
print(solve(_n, _A))

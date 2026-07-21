def solve(n, A):
    if A.count(0) > 0:
        return sum(map(abs, A))
    total = 0
    minval = 10 ** 9
    count = 0
    for a in A:
        total += abs(a)
        if a < 0:
            count += 1
        if abs(a) < minval:
            minval = abs(a)
    return total - (2 * minval if count % 2 == 1 else 0)

_n = int(input())
_A = list(map(int, input().split()))
print(solve(_n, _A))

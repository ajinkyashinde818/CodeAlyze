def solve(n, m, A, B):
    if n == m:
        if all(a == b for a, b in zip(A, B)):
            return 'Yes'
        else:
            return 'No'
    for i in range(len(A) - len(B)):
        for j in range(len(A[0]) - len(B[0])):
            if all(a[j:j + len(B[0])] == b for a, b in zip(A[i:i + len(B)], B)):
                return 'Yes'
    return 'No'

_n, _m = map(int, input().split())
_A = [input() for _ in range(_n)]
_B = [input() for _ in range(_m)]
print(solve(_n, _m, _A, _B))

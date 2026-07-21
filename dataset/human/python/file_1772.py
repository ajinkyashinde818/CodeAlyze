from itertools import product

N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [input() for _ in range(M)]

b = "".join(B)

ans = "No"
for i, j in product(range(N - M + 1), repeat=2):
    a = "".join(["".join(x[j:j + M]) for x in A[i:i + M]])
    if a == b:
        ans = "Yes"
        break
print(ans)

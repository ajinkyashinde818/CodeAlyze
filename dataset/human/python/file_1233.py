from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))
Acum = list(accumulate(A))

ans = 10 ** 20

for a in Acum[:-1]:
    snuke = a
    arai = Acum[-1] - a
    ans = min(ans, abs(snuke - arai))
print(ans)

from itertools import accumulate

N = int(input())
a = list(map(int, input().split()))
aac = list(accumulate(a))
suma = sum(a)
ans = 1e10
for i in range(0, N - 1):
    ans = min(ans, abs(suma - 2 * aac[i]))

print(ans)

n = int(input())
A = tuple(map(int, input().split()))

from itertools import accumulate
ac = [0] + list(accumulate(A))

ans = 2*10**5*(10**9)
for i in range(1, n):
    ans = min(ans, abs(ac[i] - ac[n] + ac[i]))
print(ans)

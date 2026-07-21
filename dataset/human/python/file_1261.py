n = int(input())
A = list(map(int, input().split()))

S = sum(A)

from itertools import accumulate
C = [0]+A
C = list(accumulate(C))
ans = 10**18
for i in range(1, n):
    s = C[i]
    a = S-s
    ans = min(ans, abs(s-a))
print(ans)

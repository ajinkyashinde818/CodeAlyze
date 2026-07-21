import collections

N = int(input())
ans = 0

a = []
while N % 2 == 0:
    a.append(2)
    N //= 2
f = 3
while f * f <= N:
    if N % f == 0:
        a.append(f)
        N //= f
    else:
        f += 2
if N != 1:
    a.append(N)

A = collections.Counter(a)

A = list(A.values())

for i in range(len(A)):
    cnt = 1
    val = A[i]
    while val >= cnt:
        ans += 1
        val -= cnt
        cnt += 1
print(ans)

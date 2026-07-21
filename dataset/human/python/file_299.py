import sys

N = int(input())
A = list(map(int, input().split()))


ans = 0
for a in A:
    ans += abs(a)

c = 0
m = abs(A[0])
for a in A:
    if a < 0:
        c += 1
    elif a == 0:
        print(ans)
        sys.exit()

    if abs(a) < m:
        m = abs(a)

if c % 2 == 0:
    print(ans)
else:
    print(ans - 2 * m)

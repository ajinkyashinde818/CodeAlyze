import bisect
n = int(input())
a = [int(_) for _ in input().split()]
a.sort()
i = bisect.bisect_left(a,0)
if i % 2 == 1:
    i -= 1
for j in range(i):
    a[j] *= -1
if i == n-1 or i == n:
    print(sum(a))
else:
    if a[i] + a[i+1] >= 0:
        print(sum(a))
    else:
        a[i] *= -1
        a[i+1] *= -1
        print(sum(a))

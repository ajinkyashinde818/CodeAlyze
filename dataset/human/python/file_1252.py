import itertools
n = int(input())
a = list(map(int, input().split()))

total = sum(a)
b = list(itertools.accumulate(a))

ans = pow(10, 12)
for i in range(n-1):
    ans = min(abs(b[i] - (total - b[i])), ans)

if n == 2:
    print(abs(a[0] - a[1]))
    exit()
print(ans)

import itertools
n, m = [int(i) for i in input().split()]
a = [input() for i in range(n)]
b = [input() for i in range(m)]
ans = 0
for i, j in itertools.product(range(n - m + 1), repeat = 2):
    if b == [a[i + _][j:j + m] for _ in range(m)]:
        ans = 1
print(["No", "Yes"][ans])

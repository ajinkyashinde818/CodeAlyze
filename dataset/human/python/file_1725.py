import sys

n, m = [int(i) for i in input().split()]
a = []
b = []
for i in range(n):
    a.append(input())
for i in range(m):
    b.append(input())

for ai in range(n - m + 1):
    for aj in range(n - m + 1):
        can = True
        for bi in range(m):
            if a[ai+bi][aj:aj+m] != b[bi]:
                can = False
                break
        if can:
            print('Yes')
            sys.exit(0)

print('No')

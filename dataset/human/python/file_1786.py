import sys

n, m = map(int, input().split())
a = [input() for i in range(n)]
b = [input() for i in range(m)]

for i in range(n-m+1):
    for j in range(n-m+1):
        for k in range(m):
            if a[i+k][j:j+m] != b[k]:
                break
            if k == m-1:
                print('Yes')
                sys.exit(0)
print('No')

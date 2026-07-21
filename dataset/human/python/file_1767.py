import sys

n, m = map(int, input().split())

a = []
for i in range(n):
    a.append(list(input()))

b = []
for i in range(m):
    b.append(list(input()))

for i in range(n-m+1):
    for j in range(n-m+1):
        for k in range(m):
            if k <= m-2:
                if a[i+k][j:j+m] == b[k]:
                    continue
                else:
                    break
            else:
                if a[i+k][j:j+m] == b[k]:
                    print("Yes")
                    sys.exit()
                else:
                    break

print("No")

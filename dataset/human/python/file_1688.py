import sys

n, m = list(map(int, input().split()))

a = []
for _ in range(n):
    a.append(list(input()))
    
b = []
for _ in range(m):
    b.append(list(input()))

for i in range(n - m + 1):
    for j in range(n - m + 1):
        c = [a[k][i: i + m] for k in range(j, j + m)]
        if b == c:
            print("Yes")
            sys.exit()
            
print("No")

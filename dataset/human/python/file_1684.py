import sys
n,m = map(int,input().split())
a = []
for i in range(n):
    a.append(input())
b = []
for i in range(m):
    b.append(input())

for i in range(n-m+1):
    for j in range(n-m+1):
        find = True
        for k in range(m):
            if not a[i+k][j:j+m] == b[k]:
                find = False
                break
        if find:
            print("Yes");sys.exit()
print("No")

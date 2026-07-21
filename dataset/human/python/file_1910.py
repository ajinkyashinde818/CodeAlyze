import sys
n, m = map(int, input().split())

a = []
b = []

for i in range(n):
    a.append(input())
    
for i in range(m):
    b.append(input())

for i in range(n - m + 1):
    for j in range(n - m + 1):
        flg = False
        for k in range(m):
            if flg:
                break
            for l in range(m):
                if b[k][l] != a[i + k][j + l]:
                    flg = True
                    break
        
        if flg:
            pass
        else:
            print('Yes')
            sys.exit()

print('No')

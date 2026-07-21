n, m = map(int, input().split())
a=[input()for i in range(n)]
b=[input()for i in range(m)]

def same(x,y):
    for i in range(m):
        for j in range(m):
            if a[x+i][y+j]!=b[i][j]:
                return False
    return True

for x in range (n-m+1):
    for y in range(n - m + 1):
        if same(x,y):
            print('Yes')
            import sys
            sys.exit()
print('No')

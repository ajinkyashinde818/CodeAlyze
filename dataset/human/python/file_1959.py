import sys
n,m = map(int,input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]

for y in range(n-m+1):
    for x in range(n-m+1):
        f = 1
        for i in range(m):
            for j in range(m):
                if b[i][j] == a[i+y][j+x]:
                    pass
                else:
                    f = 0
                    break
            if f == 0:
                break
        if f == 1:
            print("Yes")
            sys.exit()
print("No")

def inc(y,x):
    f = True
    for i in range(m):
        for j in range(m):
            if B[i][j] != A[y+i][x+j]:
                f = False
                break
        if not f:break
    return f
n,m = map(int,input().split())
A =[]
for i in range(n):
    A.append(input())
B = []
for i in range(m):
    B.append(input())

for y in range(n-m+1):
    for x in range(n-m+1):
        if inc(y,x):
            print("Yes")
            exit()
print("No")

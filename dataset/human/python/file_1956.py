n,m=map(int,input().split())
a=[list(input())for i in range(n)]
b=[list(input())for i in range(m)]
def match(x,y):
    for i in range(m):
        for j in range(m):
            if a[i+x][j+y]!=b[i][j]:
                return False
    return True
flag=False
for i in range(n-m+1):
    for j in range(n-m+1):
        if match(i,j):
            flag=True
if flag:
    print("Yes")
else:
    print("No")

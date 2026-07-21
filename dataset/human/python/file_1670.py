n,m=map(int,input().split())
a=[list(input())for i in range(n)]
b=[list(input()) for i in range(m)]

def judge(i,j):
    for k in range(m):
        for l in range(m):
            if b[k][l]!=a[i+k][j+l]:
                return False
    return True

for i in range(n-m+1):
    for j in range(n-m+1):
        if judge(i,j):
            print('Yes')
            exit()
print('No')

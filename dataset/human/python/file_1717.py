n,m=map(int,input().split())
master,sub=[],[]
for i in range(n):
    master.append(input())
for j in range(m):
    sub.append(input())
def chk(a,b,y,x):
    t=len(b)
    for i in range(t):
        if a[y+i][x:x+t]!=b[i]:
            return 0
    return 1

for i in range(n-m+1):
    for j in range(n-m+1):
        if master[i][j:j+m]==sub[0]:
            if chk(master,sub,i,j):
                print('Yes')
                exit()
print('No')

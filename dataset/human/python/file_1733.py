def check(y,x):
    if 0<=y<=n-1 and 0<=x<=n-1:
        return True
    return False

n,m=map(int,raw_input().split())
a=[raw_input() for _ in xrange(n)]
b=[raw_input() for _ in xrange(m)]
for i in xrange(n):
    for j in xrange(n):
        cnt=0
        for k in range(m):
            for l in xrange(m):
                if check(k+i,l+j):
                    if a[k+i][l+j]==b[k][l]:
                        cnt+=1
        if cnt==m*m:
            print("Yes")
            exit()
print("No")

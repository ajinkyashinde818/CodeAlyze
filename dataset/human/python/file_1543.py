n,m=map(int,input().split())
a=[]
b=[]
for i in range(n):
    a.append(input())
for i in range(m):
    b.append(input())
    
for i in range(n-m+1):
    if b[0] in a[i]:
        p=[]
        for j in range(n-m+1):
            if b[0]==a[i][j:j+m]:
                p.append(j)
        for j in range(1,m):
            for k in p:
                if b[j]!=a[i+j][k:k+m]:
                    p.remove(k)
        if p!=[]:
            print("Yes")
            import sys
            sys.exit()
print("No")

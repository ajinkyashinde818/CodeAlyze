n,m=map(int,input().split())
a,b=[],[]
for i in range(n):
    a.append(list(input()))
for i in range(m):
    b.append(list(input()))
num=n-(m-1)
ok=0 #一致したやつが０
def check(y,x):
    c=1 #一致した
    for i in range(m):
        for j in range(m):
            if a[y+i][x+j]!=b[i][j]:
                c=0
                break
        if c==0:
            break
    return c
for i in range(num):
    for j in range(num):
        #print(str(i)+str(j))
        if check(i,j)==1:
            ok=1
            break
    if ok==1:
        break
            
print("Yes" if ok==1 else "No")

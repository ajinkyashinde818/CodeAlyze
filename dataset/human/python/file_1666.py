n,m=map(int,input().split())
a=[]
b=[]
for i in range(n): 
    a.append(input())
for i in range(m):
    b.append(input())
def check(i,j): 
    if i+m>n or j+m>n:
        return 0 
    a1=-1 
    for x in range(i,i+m):
        a1+=1 
        b1=0 
        for y in range(j,j+m):
            if b[a1][b1]!=a[x][y]:
                return 0 
            b1+=1 
    return 1 
for i in range(n):
    for j in range(n): 
        if check(i,j):
            print('Yes')
            exit()
print('No')
#print(a,b)

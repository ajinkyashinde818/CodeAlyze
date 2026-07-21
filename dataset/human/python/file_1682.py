import sys
n,m=map(int,input().split())
a=[]
b=[]
for x in range(n):
    a.append(input())
for y in range(m):
    b.append(input())
for z in range(n-m+1):
    k=0
    l=0
    for w in range(n-m+1):
        if (a[w])[z:z+m]==b[k]:
            l+=1
            k+=1
            if l==m:
                print('Yes')
                sys.exit()
else:
    print('No')

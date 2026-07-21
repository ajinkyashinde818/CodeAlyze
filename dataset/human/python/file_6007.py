def linp():return list(map(int,input().split()))
n=int(input())
a=linp()
b=linp()
c=linp()
s=b[a[0]-1]
for i in range(1,n):
    s+=b[a[i]-1]
    if a[i]-a[i-1]==1:s+=c[a[i-1]-1]
print(s)

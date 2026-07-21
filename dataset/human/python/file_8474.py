import sys
(k,n)=map(int,input().split())
a=input().split()
n-=1
j=int(a[n])-int(a[0])
l=0
for i in range(n):
  l=int(a[(n+i+1)%(n+1)])+k-int(a[i+1])
  if(j>l):
    j=l
print(j)

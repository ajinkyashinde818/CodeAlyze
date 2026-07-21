import sys
import numpy

n,k=map(int,input().split())
a=list(map(int,input().split()))
b=numpy.zeros(n,dtype=int)

city=1
count=0
while b[city-1]==0:
    count+=1
    b[city-1]=1
    
    city=a[city-1]

#arrive at city in count, len(cl)=count
if k<count:
    cc=1
    for i in range(k):
        cc=a[cc-1]
    print(cc)
    sys.exit()

c=1
cnt=0
while c!=city:
    cnt+=1
    c=a[c-1]

loop=count-cnt

d=(k-count)%loop

for i in range(d):
    city=a[city-1]

print(city)

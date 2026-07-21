def i1():
 return int(input())
def i2():
 return [int(i) for i in input().split()]
[d,g]=i2()
e=[0 for i in range(1001)]

for i in range(1,d+1):
 [p,c]=i2()
 ee=e[:]
 for j in range(p-1):
   for k in range(1000)[::-1]:
    if e[k]>0 or k==0:
      e[k+1]=max(e[k+1],e[k]+100*i)
 
 for k in range(1001-p)[::-1]:
      if(ee[k]>0 or k==0):
        ee[k+p]=max(ee[k+p],ee[k]+100*i*p+c)
        e[k+p]=max(e[k+p],ee[k+p])
 
 
for i in range(1001):
 if e[i]>=g:
    print(i)
    break

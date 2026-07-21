from collections import Counter

n,k=map(int,input().split())
a=list(map(int,input().split()))

city=[0]*n
city[0]+=1
dict={}
for x in range(n-1):
  b=city[x]-1
  c=a[b]
  city[x+1]+=c
  
for y in range(n):
  d=city[y]
  e=str(d)
  if e in dict:
    check=d
    end=y
    break
  if  e not in dict:
    dict[e]=y

start=city.index(d)
w=end-start
if k<start:
  print(city[k])
  
else:
  kk=k-start
  rest=kk%w
  q=start+rest
  print(city[q])

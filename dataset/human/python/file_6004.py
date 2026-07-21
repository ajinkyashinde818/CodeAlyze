from operator import itemgetter
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
l=[]
for i in range(n):
  l.append([i,a[i],b[i]])
l.sort(key=itemgetter(1))
cost = 0
for i in range(n):
  val = l[i][1]
  ix = l[i][0]; previx = -2
  if(i!=0):
    previx = l[i-1][0]
  cost+=(l[i][2])
  if(previx+1==ix):
    cost+=(c[i-1])
print(cost)

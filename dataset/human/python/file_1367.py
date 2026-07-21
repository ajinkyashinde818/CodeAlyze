import itertools
n=int(input())
l=list(map(int,input().split()))
cul=list(itertools.accumulate(l))
sum=cul[-1]
tmp=abs(cul[0]-sum/2)
for i in range(1,n-1):
  if tmp>abs(cul[i]-sum/2):
    tmp=abs(cul[i]-sum/2)
print(int(2*tmp))

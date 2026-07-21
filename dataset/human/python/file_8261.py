def main(n,a):
  sa=sum(a)
  tmp=(n*(n+1))//2
  if sa%tmp!=0:
    return 'NO'
  cnt=sa//tmp
  chk=0
  for i in range(n):
    t=a[i]-a[i-1]
    t-=cnt
    if t==0:continue
    if t%n!=0:return 'NO'
    chk+=abs(t)//n
  if cnt==chk:return 'YES'
  return 'NO'

n=int(input())
a=list(map(int,input().split()))
print(main(n,a))

def p_fact(n):
  m=n
  i=2
  a=[]
  while n>1:
    if i>m**.5:
      a+=[n]
      break
    if n%i==0:
      n//=i
      a+=[i]
    else:i+=1
  return a
a=p_fact(int(input()))
d={}
for i in a:
  if d.get(i):d[i]+=1
  else:d[i]=1
ans=0
for i in d:
  j=1
  while d[i]-j>=0:
    ans+=1
    d[i]-=j
    j+=1
print(ans)

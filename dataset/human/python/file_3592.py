import bisect as bi
def fact(n):
  arr=[]
  temp=n
  for i in range(2,int(-(-n**0.5//1))+1):
    if temp%i==0:
      cnt=0
      while temp%i==0:
        cnt+=1
        temp//=i
      arr.append([i,cnt])
  if temp!=1:
    arr.append([temp,1])
  if arr==[]:
    arr.append([n,1])
  return arr
n=int(input())
if n==1:
  print(0)
  exit()
l=[i*(i+1)//2 for i in range(1,100)]
c=0
for t in fact(n):
  c+=bi.bisect_right(l,t[1])
print(c)

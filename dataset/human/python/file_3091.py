from collections import Counter
n=int(input())
def soin(n):
  soin_ans=[]
  while n%2==0:
    n//=2
    soin_ans.append(2)
  f=3
  while f<=n**0.5:
    if n%f==0:
      n//=f
      soin_ans.append(f)
    else:
      f+=2
  if n!=1:
    soin_ans.append(n)
  return soin_ans
s_list=soin(n)
s_set=set(s_list)
sc=Counter(s_list)
count=0
for i in s_set:
  for j in range(1,sc[i]+1):
    if n%i**j==0:
      n//=i**j
      count+=1
print(count)

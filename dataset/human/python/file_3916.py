from collections import Counter
def p_factorization(n):
  p=[]
  for i in range(2,int(n**0.5)+1):
    while n%i==0:
      p.append(i)
      n//=i
  if n>1:
    p.append(n)
  return p
n=int(input())
ans=0
for pi in Counter(p_factorization(n)).items():
  x=pi[1]
  for i in range(50):
    if i*(i+1)//2<=x<(i+1)*(i+2)//2:
      ans+=i
      break
print(ans)

from collections import defaultdict
def prime_factorization(n):
  if n==1:
    return {}
  res=defaultdict(int)
  for f in range(2,n):
    if f*f>n:
      break
    while n%f==0:
      n=n//f
      res[f]+=1
  if n>1:
    res[n]+=1
  return res

def cnt_ope(n):
  return min(k for k in range(n+1) if (k+2)*(k+1)//2>n)

def main():
  fac=prime_factorization(int(input()))
  return sum(cnt_ope(cnt) for cnt in fac.values())
print(main())

n=int(input())

def divisore(n):
    divisors=[]
    for i in range(1,int(n**0.5)+1):
        if n%i==0:
            divisors.append(i)
            if i!=n//i:
                divisors.append(n//i)
    divisors.sort()
    return divisors

def factorization(n):
    p=2
    fcr=[]
    while p*p<=n:
        while n%p==0:
            fcr.append(p)
            n//=p
        p+=1
    if n>1:
        fcr.append(n)
    return fcr

l=divisore(n)[1:]

ans=0
for i in l:
  t_l=factorization(i)
  if len(set(t_l))!=1:
    continue

  if n%i==0:
    ans+=1
    n//=i

print(ans)

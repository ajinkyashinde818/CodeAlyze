def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            a=n//i 
            if (a+1)*i<=n:
              a+=1
            n=a
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors
N=int(input())
a=prime_factors(N)
current=0
index=0
anslist=[]
for i in a:
  if i!=current:
    current=i
    anslist.append(1)
  else:
    anslist[-1]+=1
ans=0
for i in anslist:
  k=1
  while (k*(k+1))<=2*i:
    k+=1
  k-=1
  ans+=k
print(ans)

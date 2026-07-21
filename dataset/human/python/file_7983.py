k,n =map(int,input().split())
mod = 998244353
fact = [1]*(n+k+1)
rfact = [1]*(n+k+1)
for i in range(n+k):
    fact[i+1] = rr = ((i+1) * fact[i]) % mod
    rfact[i+1] = pow(rr, mod-2, mod)
def comb(N, K,mod):
    return fact[N] * rfact[K] * rfact[N-K] % mod
kota = []
for i in range(2,k+2):
  ans = 0
  if i %2 == 1:
    pp = (i+1)//2
    pm = i - pp
    p = min(k-pp+1,pm)
    for q in range(p+1):
      sen = comb(p,q,mod)*pow(2,q,mod)%mod
      if n - q<0:
        break
      r = k-p*2
      if r <0:
        r = 0
      if n+r-1 < n-q:
        continue
      ans += sen* comb(n+r-1,n-q,mod)%mod
    kota.append(ans%mod)
  else:
    pp = i//2 +1
    pm = i//2 -1
    p = min(k-pp+1,pm)
    for q in range(p+1):
      sen = comb(p,q,mod)*pow(2,q,mod)%mod
      if n - q<0:
        break
      r = k-p*2-1
      if r <0:
        r = 0
      if n+r-1 < n-q:
        continue
      ans += sen* comb(n+r-1,n-q,mod)%mod
    for q in range(p+1):
      sen = comb(p,q,mod)*pow(2,q,mod)%mod
      if n - q-1<0:
        break
      r = k-p*2-1
      if r <0:
        r = 0
      if n+r-2 < n-q-1:
        continue
      ans += sen* comb(n+r-2,n-q-1,mod)%mod
    kota.append(ans%mod)
for i in kota:
  print(i)
for i in range(len(kota)-2,-1,-1):
  print(kota[i])

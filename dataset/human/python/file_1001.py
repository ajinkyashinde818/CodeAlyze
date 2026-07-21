from collections import Counter
mod = 10**9+7
mod2 = 998244353
rng = 100100
fctr = [1]
finv = [1]
for i in range(1,rng):
  fctr.append(fctr[-1]*i%mod)
for i in range(1,rng):
  finv.append(pow(fctr[i],mod-2,mod))
def cmb(n,k):
  if n<0 or k<0:
    return 0
  else:
    return fctr[n]*finv[n-k]*finv[k]%mod
n = int(input())
s = input()
a = [0]*(2*n)
a[0] = 1
for i in range(1,2*n):
  if s[i-1] == s[i]:
    a[i] = a[i-1]
  else:
    if i == 1:
      a[i] = a[i-1]+1
    else:
      if a[i-1] != a[i-2]:
        a[i] = 2*a[i-1]-a[i-2]
      if (i+a[i-1])%2 == 0:
        a[i] = a[i-1]+1
      else:
        a[i] = a[i-1]-1
if a[-1] != 1 or a.count(0) >= 1 or s[0] != "B" or s[-1] != "B":
  print(0)
  exit()
c = Counter(a)
ans = 1
for i,x in c.items():
  ans = (ans*pow(i,x//2,mod))%mod
ans = ans*fctr[n]%mod
print(ans)

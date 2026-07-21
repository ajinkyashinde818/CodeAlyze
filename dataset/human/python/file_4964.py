n = int(input())
mod = 10 ** 9 + 7
a = list(map(int,input().split()))
b = []
for i in range(1,n):
  b.append(a[i]-a[i-1])
c = [1]
def inv(x):
  y = 1
  while x != 1:
    y *= mod // x + 1
    y %= mod
    x -= mod % x
  return y
#print(inv(5))
#print(inv(2))
for i in range(2,n):
  c.append((c[-1]+inv(i))%mod)
#print(c)
ans = 0
for i in range(n-1):
  ans += c[i] * b[i]
  ans %= mod
fact = 1
for i in range(1,n):
  fact *= i
  fact %= mod
ans *= fact
ans %= mod
print(ans)

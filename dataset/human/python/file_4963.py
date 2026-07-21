N = int(input())
A = list(map(int, input().split()))
mod = int(1e+9 + 7)
def inved(a):
  x, y, u, v, k, l = 1, 0, 0, 1, a, mod
  while l != 0:
    x, y, u, v = u, v, x - u * (k // l), y - v * (k // l)
    k, l = l, k % l
  return x

frac = 1
for i in range(N - 1):
  frac *= i+1
  frac %= mod
T = 0
for i in range(N - 1):
  k = inved(i+1)
  T += (k * (A[N - 1] - A[i])) % mod
  T %= mod
print((T*frac)%mod)

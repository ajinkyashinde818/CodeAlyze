import sys
sys.setrecursionlimit(1000000)

n = int(input())
x = list(map(int, input().split()))
d = [x[i+1] - x[i] for i in range(n - 1)]

def pow(x, y):
    if y == 0:
        return 1
    ans = 1
    while y > 1:
        if y % 2 != 0:
            ans *= x
            ans %= 1000000007
        x *= x
        x %= 1000000007
        y //= 2
    return ans * x % 1000000007

def fact(m):
  return m * fact(m-1) % 1000000007 if m != 1 else 1
 
fact_n_1 = fact(n-1)

e = [None] * (n-1)
for i in range(n-1):
  if i == 0:
    e[i] = fact_n_1
  else:
    e[i] = (e[i - 1] + fact_n_1 * pow(i + 1, 1000000005)) % 1000000007

print(sum(e_i * d_i % 1000000007
          for i, (d_i, e_i) 
          in enumerate(zip(d, e))) % 1000000007 )

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())

def prime_factorize(n):
  ret = []
  for i in range(2, int(n ** (1 / 2)) + 1):
    if i > n:break
    cnt = 0
    while n % i == 0:
      n //= i
      cnt += 1
    if cnt > 0:  
      ret.append((i, cnt))
  if n != 1:
    ret.append((n, 1))
  return ret

lis = prime_factorize(N)

ans = 0

for v, cnt in lis:
    i = 1
    while cnt >= i:
        cnt -= i
        i += 1   
    ans += i - 1
print(ans)

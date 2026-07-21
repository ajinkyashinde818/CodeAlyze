N = int(input())

p_dic = {}
i=2
while i ** 2 <= N:
  if N % i == 0:
    p_dic[i] = 0
    while N % i == 0:
      p_dic[i] += 1
      N /= i
  i += 1

if N > 1:
  p_dic[N] = 1
  
def foo(x):
  r = 0
  base = 1
  while x >= base:
    x -= base
    r+=1
    base += 1
  return r

ans = 0
for v in p_dic.values():
#  print(v, foo(v))
  ans += foo(v)

print(ans)

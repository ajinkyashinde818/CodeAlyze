import math

D, G = map(int, input().split())
p = [0] * D
c = [0] * D
for i in range(D):
  p[i], c[i] = map(int, input().split())

ans = 1e9
for mask in range(1 << D):
  s, num, rest_max = 0, 0, -1
  for i in range(D):
    if mask >> i & 1:
      s += 100 * (i+1) * p[i] + c[i]
      num += p[i] # 問題数
    else:
      rest_max = i # 完全に解いた問題以外のうち最大点数の問題

  if s < G: # Gに満たない
    s1 = 100 * (rest_max + 1)
    need = math.ceil((G - s) / s1)     
    if need >= p[rest_max]:
      continue # 完全に解く＋中途半端に解くがG点に満たない
    num += need
  
  ans = min(ans, num)
    
print(ans)

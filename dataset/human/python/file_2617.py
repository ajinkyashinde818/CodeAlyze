import math
D,G = map(int,input().split())
L = []
for i in range(D):
  L.append(list(map(int,input().split())))
n = 2
ans = float('inf')
def Base_10_to_n(X, n):
  if (int(X/n)):
      return Base_10_to_n(int(X/n),n)+str(X%n)
  return str(X%n)
for i in range(2**D):
  K = Base_10_to_n(i, n).zfill(D)
  S = 0
  sub = 0
  for j in range(D):
    if K[j] == '1':
      S += L[j][0]*100*(j+1)+L[j][1]
      sub += L[j][0]
  if S >= G:
    if sub <= ans:
      ans = sub
  else:
    cnt = 0
    for l in range(D):
      if cnt == 0:  
        if K[D-l-1] == '0':
          cnt = 1
          if G-S <= L[D-l-1][0]*100*(D-l)+L[D-l-1][1]:
            if G-S > L[D-l-1][0]*100*(D-l):
              if ans >= sub+L[D-l-1][0]:
                ans = sub+L[D-l-1][0]
            else:
              if ans >= sub+math.ceil((G-S)/(100*(D-l))):
                ans = sub+math.ceil((G-S)/(100*(D-l)))
print(ans)

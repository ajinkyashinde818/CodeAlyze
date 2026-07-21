D, G = map(int, input().split())
from itertools import chain

S = []
for i in range(D):
  p, c = map(int, input().split())
  S.append((p, c))

L = []
for i in range(2**D):
  T = []
  for j in range(D):
    if (i>>j) & 1:
      T.append(j)
  L.append(T)

X = []
for l in L:
  score, count = 0, 0
  for m in l:
    p, c = S[m]
    score += c + (m+1) * 100 * p
    count += p
  else:
    X.append((score,count,l))

ans = float("inf")
for l in X:
  score, count, indexes = l

  if score >= G:
    ans = min(ans, count)
    continue
  
  end = False
  for i in list(range(D))[::-1]:
    if i in indexes:
      continue

    if end:
      break
    
    p, c = S[i]
    for _ in range(p):
      count += 1
      score += (i+1) * 100
      if score >= G:
        ans = min(ans, count)
        end = True
        break

print(ans)

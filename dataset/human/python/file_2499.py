def lastjudge(L, i, G):
  mi = 1000
  for j in L:
    if j[4] == 0:
      if j[3] < G:
        continue
      elif j[3] - j[1] > G:
        t = -(-G // j[2])
      else:
        t = j[0]
      if mi > t:
        mi = t
  return mi
def judge(L, i, G):
  if i+1 < len(L):
    m = judge(L, i+1, G)
    if L[i][3] >= G:
      if L[i][3] - L[i][1] > G:
        t = -(-G // L[i][2])
      else:
        t = L[i][0]
    else:
      G -= L[i][3]
      L[i][4] = 1
      t = L[i][0] + judge(L, i+1, G)
    return min(t, m)
  else:
    m = lastjudge(L, i, G)
    if L[i][3] < G:
      G -= L[i][3]
      L[i][4] = 1
      t = L[i][0] + lastjudge(L, i, G)
    elif L[i][3] - L[i][1] > G:
      t = -(-G // L[i][2])
    else:
      t = L[i][0]
    return min(t, m)
 
D, G = list(map(int,input().split()))
L = []
for i in range(D):
  L.append(list(map(int, input().split())))
  L[i].append((i+1) * 100)
  L[i].append(L[i][0] * L[i][2] + L[i][1])
  L[i].append(0)
print(judge(L, 0, G))

import itertools
D, G = map(int, input().split())
ans = 10000000000
list_pro = [list(map(int, input().split())) for _ in range(D)]
for ptr in itertools.product([0,1], repeat=D):
  cnt_pro = 0
  res = 0
  for i,k in enumerate(ptr):
    if k == 1:
      cnt_pro += list_pro[i][0]
      res += 100 * (i+1) * list_pro[i][0] + list_pro[i][1]
  if res < G:
    for j, l in enumerate(reversed(ptr)):
      if l == 0:
        for _ in range(list_pro[D-1-j][0]):
          if res >= G:
            break
          res += 100 * (D-j)
          cnt_pro += 1      
  if res >= G:
    ans = min(ans, cnt_pro)
print(ans)

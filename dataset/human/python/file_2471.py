import math

D, G = map(int, input().split())
ans = 10**7
problems = [tuple(map(int, input().split())) for _ in range(D)]
for num in range(2**D):
  solve = 0
  point = 0
  last = -1
  for i in range(D):
    if num>>i&1:
      point += problems[i][1] + (i+1)*100*problems[i][0]
      solve += problems[i][0]
    else:
      last = i
  if last == -1:
    ans = min(ans, solve)
  else:
    rest = G - point
    if rest <= 0:
      ans = min(ans, solve)
    else:
      if rest <= (last+1)*100*problems[last][0]:
        ans = min(ans, solve+math.ceil(rest/((last+1)*100)))
print(ans)

N = int(input())

c = N*2
import math
cl, cr = math.ceil(math.sqrt(c)), math.floor(math.sqrt(c))
if cl==cr+1 and cl*cr==c:
  k = cl
  print('Yes')
  ans = [[] for _ in range(k)]
  print(k)
  num = 1
  for i in range(k-1):
    for j in range(i+1, k):
      ans[i].append(num)
      ans[j].append(num)
      num += 1
  for arr in ans:
    print(len(arr), *arr, sep=' ')
else:
  print('No')

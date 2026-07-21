import itertools

n = int(input())
triangle = [0,0]
now = 0
num = 1
while now < n:
  now += num
  triangle.append(now)
  num += 1
if n in triangle:
  print("Yes")
  K = triangle.index(n)
  print(K)
  ans = [list() for i in range(K)]
  for k,v in enumerate(itertools.combinations(range(K),2),1):
    for i in v:
      ans[i].append(k)
  for i in ans:
    print(K-1,*i)
else:
  print("No")

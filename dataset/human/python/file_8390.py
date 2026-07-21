import numpy as np

k, n = map(int, input().split())
a = list(map(int, input().split())) 

dist = []
dist.append(a[1]-a[0])

for num in range(1, len(a)):
  if num == len(a) - 1:
    dist.append(k-a[num]+a[0])
  else:
    dist.append(a[num+1]-a[num])
#print(dist)
dist = np.array(dist)

#min_index = np.where(dist == dist.min())[0]
s = np.sum(dist)
result = []
for start_index in range(0, len(dist)):
  if start_index == 0:
    result.append(s - dist[len(dist)-1])
    result.append(s - dist[start_index+1])
  elif start_index == len(dist)-1:
    result.append(s - dist[start_index-1])
    result.append(s - dist[0])
  else:
    result.append(s - dist[start_index-1])
    result.append(s - dist[start_index+1])
print(min(result))

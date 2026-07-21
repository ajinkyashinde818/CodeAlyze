k,n = [int(x) for x in input().split()]
l = [int(x) for x in input().split()]
from collections import deque
d = deque()
d.append(k-l[n-1]+l[0])
for i in range(n-1):
  d.append(l[i+1]-l[i])
print(k-max(d))

import numpy as np

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))     

s = np.sum(b)
for i in range(n):
  a[i] = a[i] -1

t = a[0]
for i in range(1, len(a)):
  if (t+1) == a[i]:
    s = s + c[a[i]-1]
  t = a[i]
print(s)

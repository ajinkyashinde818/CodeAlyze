import numpy as np

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

if a[0] == 1:
  print(1)
  exit()
  
log = np.full(n, -1)
log[0] = 0
step = 0
now = 0
flag = 0
while step < k:
  now = a[now] - 1
  step += 1
  if log[now] != -1:
    flag = 1
    break
  else:
    log[now] = step

if flag == 0:
  print(now+1)
  exit()

loop = step - log[now]
remain = k - step
if remain > loop:
  remain = remain % loop

for i in range(remain):
  now = a[now] - 1
print(now+1)

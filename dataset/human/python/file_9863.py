import sys
N, K = map(int, input().split())
A = list(map(int, input().split()))

already = [False] * N
step = 0
now = 1
count = 0
while(already[now-1] != True):
    already[now - 1] = True
    now = A[now - 1]
    count += 1
    if count == K:
      print(now)
      exit(0)
loop = 0
cycle = 0
if(now == 1):
    step = 0
    cycle = count
    loop = K % cycle
else:
    step = 0
    temp = 1
    while(temp != now):
        temp = A[temp - 1]
        step += 1
    cycle = count - step
    loop= (K - step) % cycle

temp = 1
for i in range(step + loop):
    temp = A[temp - 1]
print(temp)

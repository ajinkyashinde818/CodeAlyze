from collections import deque

N, K = map(int, input().split())
towns = [0] + list(map(int, input().split()))
checked = [-1 for _ in range(N+1)]
checked[1] = 0
next = towns[1]
count = 1
    
while(checked[next] < 0):
  checked[next] = count
  count += 1
  next = towns[next]
loop = count - checked[next]
pos = 0
if K >= count:
  pos = checked[next] + (K-checked[next])%loop
else:
  pos = K
for i in range(1, N+1):
  if checked[i] == pos:
    print(i)
    exit()

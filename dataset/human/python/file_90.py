from statistics import median
R,G,B,N = map(int,input().split())
count = 0
n_max = max(R,G,B)
n_mid = median([R,G,B])
n_min = min(R,G,B)
for i in range(N//n_max + 1):
  x = N - i*n_max
  for j in range(x//n_mid + 1):
    y = x - j*n_mid
    if y % n_min == 0:
      count += 1
print(count)

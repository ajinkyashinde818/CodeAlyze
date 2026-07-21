K, N = map(int, input().split())
An = list(map(int, input().split()))

def distance(a1, a2):
  return abs(a1 - a2)

sum, max = 0, 0
for i in range(N):
  if (i + 1) < N:
    d = distance(An[i], An[i+1])
    sum += d
    if(d > max):
      max = d
  else:
    d = distance(An[i], K) + distance(0, An[0])
    sum += d
    if(d > max):
      max = d

print(sum - max)

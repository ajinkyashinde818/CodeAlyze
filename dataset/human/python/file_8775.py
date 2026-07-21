import statistics

k, n = map(int, input().split())
a = list(map(int, input().split()))
dist = []

for num, i in enumerate(a[:]):
  if num == (n - 1):
    dist.append(abs((k + a[0]) - i))
  else:
    dist.append(abs(a[num + 1] - i))
ind = dist.index(max(dist))
dist.pop(ind)
print(sum(dist))

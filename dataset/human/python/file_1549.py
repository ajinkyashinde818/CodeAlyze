def solve(n, m, a, b):
  for i in range(n - m + 1):
    for j in range(n - m + 1):
      if [row[j:j+m] for row in a[i:i+m]] == b:
        return True
  return False

n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]
print('Yes' if solve(n, m, a, b) else 'No')

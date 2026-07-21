n, m = [int(i) for i in input().split()]

def subdata(a, i, j):
  return [row[j:j + m] for row in a[i:i + m]]

def template_matching(a, b):
  for i in range(n - m + 1):
    for j in range(n - m + 1):
      if subdata(a, i, j) == b:
        return "Yes"
  return "No"

print(template_matching([input() for _ in range(n)], [input() for _ in range(m)]))

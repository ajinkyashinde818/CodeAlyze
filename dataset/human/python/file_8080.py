K, S = map(int, input().split())

def f():
  if K * 3 >= S:
    for x in range(min(K, S), -1, -1):
      if K * 2 >= S - x:
        for y in range(min(K, S - x), -1, -1):
          if K >= S - x - y:
            yield 1

print(sum(list(f())))

def search(width, books, m):
  acc = 0
  cnt = 1
  for book in books:
    if book > width:
      return False
    if acc + book > width:
      cnt += 1
      acc = book
    else:
      acc += book
  return cnt <= m
while True:
  m, n = map(int, input().split())
  if m == 0:
    break
  books = [int(input()) for _ in range(n)]
  left = 0
  right = 1500000
  while right - left > 1:
    mid = (left + right) // 2
    #print(mid)
    if search(mid, books, m):
      right = mid
    else:
      left = mid
  print(right)

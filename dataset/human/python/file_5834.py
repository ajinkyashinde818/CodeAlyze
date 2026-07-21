def resolve():
  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))
  c = list(map(int, input().split()))

  ans = 0
  prev = -2
  for x in a:
    x -= 1
    ans += b[x]
    if prev + 1 == x:
      ans += c[prev]
    prev = x
  print(ans)
  return

if __name__ == "__main__":
  resolve()

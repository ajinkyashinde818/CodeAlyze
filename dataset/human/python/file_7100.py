from collections import deque
def main():
  s = deque(list(input()))
  q = int(input())
  f = 0
  for _ in range(q):
    l = input()
    if l == "1":
      f ^= 1
    else:
      a, b, c = l.split()
      if f ^ (b=="1"):
        s.appendleft(c)
      else:
        s.append(c)
  if f:
    ans = list(s)[::-1]
  else:
    ans = list(s)
  print(*ans, sep="")
if __name__ == "__main__":
  main()

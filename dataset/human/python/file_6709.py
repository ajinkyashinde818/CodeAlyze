from collections import deque
def main():
  s = deque(list(input()))
  q = int(input())
  sr = s.reverse
  sa = s.append
  sal = s.appendleft

  cnt = 0
  for _ in range(q):
    t = input()
    if t[0] == "1":
      cnt += 1
    else:
      _,f,c = t.split(" ")
      if f == "1":
        if cnt%2==1:
          sa(c)
        else:
          sal(c)
      else:
        if cnt%2==1:
          sal(c)
        else:
          sa(c)
  if cnt%2 == 1:
    sr()
  print("".join(list(s)))

if __name__=="__main__":
  main()

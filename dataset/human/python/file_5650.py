import math
def solve():
  s = input()
  n = len(s)
  ct = 0
  mae = -1
  usiro = 0
  times = (n+1)//2
  tim = 0
  while tim < times:
    tim += 1
    mae += 1
    usiro -= 1
    if s[mae] == s[usiro]:
      continue
    else:
      if s[mae] == "x":
        ct += 1
        usiro += 1
        tim -= 0.5
      elif s[usiro] =="x":
        ct += 1
        mae -= 1
        tim -= 0.5
      else:
        print("-1")
        exit()
  print(ct)

solve()

import sys
from collections import deque
def main():
  S = input()
  Q = int(input())
  r = False
  ans = deque(S)
  for l in sys.stdin:
    TFC = l.split()
    if TFC[0]=="1": r = not r
    elif TFC[1]=="1":
      if r: ans.append(TFC[2])
      else: ans.appendleft(TFC[2])
    elif TFC[1]=="2":
      if r: ans.appendleft(TFC[2])
      else: ans.append(TFC[2])
  print("".join(reversed(ans) if r else ans))

if __name__ == "__main__":
  main()

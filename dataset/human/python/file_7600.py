import sys
def input(): return sys.stdin.readline().rstrip()

from collections import deque

def main():
  S = deque(input())
  N = int(input())

  d = True
  for i in range(N):
    list = input().split()
    if list[0] == '1':
      d = not d
      continue
    if list[1] == '1':
      S.appendleft(list[2]) if d else S.append(list[2])
      continue
    S.append(list[2]) if d else S.appendleft(list[2])
  return ''.join(S) if d else ''.join(S)[::-1]

if __name__ == '__main__':
  print(main())

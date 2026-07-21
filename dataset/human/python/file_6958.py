from collections import deque
from sys import stdin
input = stdin.readline


def main():
  S = input()[:-1]
  Q = int(input())

  q = deque([S])
  reverse = False
  for i in range(Q):
    line = input().split()
    if line[0] == '1':
      reverse = not(reverse)
    else:
      if reverse ^ (int(line[1])-1):
        # S = S + line[2]
        q.append(line[2])
      else:
        # S = line[2] + S
        q.appendleft(line[2])

  print(''.join(list(reversed(''.join(q)))) if reverse else ''.join(q))


if(__name__ == '__main__'):
  main()

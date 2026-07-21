import sys
import math
import itertools

def main():
  n,k = map(int, input().split())
  a = list(map(int,sys.stdin.readline().split()))

  now = 0
  times = 0
  visit =[[0],[-1 for _ in range(n)]]
  visit[1][0] = 0
  roop = 0
  roop_start = 0

  for _ in range(k):
    times += 1
    now = a[now] - 1

    if visit[1][now] != -1:
      roop_start = visit[1][now] #ループが始めった待ちの最初に訪れた時に何回ループしていたかをroop_startに代入
      roop = times - roop_start #何個の町でループしてるかをroopに代入
      break
    else:
      visit[0].append(now)
      visit[1][now] = len(visit[0]) - 1

  if roop > 0:
    k = (k - roop_start) % roop

  # print(roop_start)
  # print(roop)
  # print(k)
  # print(visit[0])
  print(visit[0][roop_start + k] + 1)

  # now = 0
  # for _ in range(roop_start):
  #   now = a[now] - 1

  # for _ in range(k):
  #   now = a[now] -1

  # print(now+1)


if __name__ == '__main__':
  main()

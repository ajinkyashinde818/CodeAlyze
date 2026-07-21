import math
def I():
  return input()
def II():
  return int(input())
def MII():
  return map(int, input().split())
def LMII():
  return list(map(int, input().split()))

n, r = MII()
print(r+100*max((10-n), 0))

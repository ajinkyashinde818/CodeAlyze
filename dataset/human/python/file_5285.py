import sys
input = sys.stdin.readline
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N,M = IL()

data = [0]*N
for i in range(M):
  a,b = IL()
  if a == 1:
    if data[b]==1:
      print("POSSIBLE")
      break
    else:
      data[b]=1
  if b == N:
    if data[a]==1:
      print("POSSIBLE")
      break
    else:
      data[a]=1
else:
  print("IMPOSSIBLE")

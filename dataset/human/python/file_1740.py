import sys
input = sys.stdin.readline
N, M = map(int, input().split())
a = [list(input())[: -1] for _ in range(N)]
b = [list(input())[: -1] for _ in range(M)]
for i in range(N - M + 1):
  for j in range(N - M + 1):
    for y in range(M):
      for x in range(M):
        if a[i + y][j + x] != b[y][x]: break
      else: continue
      break
    else:
      print("Yes")
      exit(0)
print("No")

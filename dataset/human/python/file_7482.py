import sys
sys.setrecursionlimit(10 ** 7)
read = sys.stdin.buffer.read 
inp = sys.stdin.buffer.readline
def inpS(): return inp().rstrip().decode()
readlines = sys.stdin.buffer.readlines 
MOD = 10**9+7

from collections import deque

S = deque(inpS())
Q = int(inp())
Query = [list(inpS().split())for _ in range(Q)]
is_revese = False

for q in Query:
  if q[0] == "1":
    is_revese = not is_revese
  else:
    if q[1] == "1": # 先頭に追加
      if is_revese: #反転状態
        S.append(q[2])
      else:
        S.appendleft(q[2])
    else:
      if is_revese: #反転状態
        S.appendleft(q[2])
      else:
        S.append(q[2])

if is_revese:
  S = reversed(S)
print("".join(S))

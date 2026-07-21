import sys
import resource
sys.setrecursionlimit(10 ** 9)

S = input()
l = []
def dfs(n):
  if n == len(S):
    l.append("YES")
  if n < len(S):
    if S[n:n+5] == "erase":
      dfs(n+5)    
    if S[n:n+5] == "dream":
      dfs(n+5)  
    if S[n:n+6] == "eraser":
      dfs(n+6)              
    if S[n:n+7] == "dreamer":
      dfs(n+7)
dfs(0)
if len(l) == 0:
  l.append("NO")
print(l[0])

words = ("dream","dreamer","erase","eraser")
import sys
readline = sys.stdin.readline

S = readline().rstrip()

stack = [0]
while stack:
  ind = stack.pop()
  if ind == len(S):
    print("YES")
    break
  for w in words:
    if S[ind:ind + len(w)] == w:
      stack.append(ind + len(w))
else:
  print("NO")

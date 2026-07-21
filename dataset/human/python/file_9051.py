import sys
sys.setrecursionlimit(50000)

S = input()
S_len = len(S)

def dd(i):
  if i >= S_len: return True
  for ex in ("dream","dreamer","erase","eraser"):
    length = i + len(ex)
    if ex == S[i:length]:
      if dd(length): return True
  return False

print("YES" if dd(0) else "NO")

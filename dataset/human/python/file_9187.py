S = input()

S = S[::-1]

def solve(s):
  words = [
    'dreamer'[::-1],
    'eraser'[::-1],
    'dream'[::-1],
    'erase'[::-1],
  ]
  while s:
    for w in words:
      if s.startswith(w):
        s = s[len(w):]
        break
    else:
      return False
  return True

if solve(S):
  print('YES')
else:
  print('NO')

import sys

s = sys.stdin.read().strip()
words = ["dream", "dreamer", "erase", "eraser"]

stack = [0]
match = False
while not match and stack:
  i = stack.pop()
  for w in words:
    if s.startswith(w, i):
      n = i + len(w)
      if n == len(s):
        match = True
        break
      stack.append(n)
print("YES" if match else "NO")

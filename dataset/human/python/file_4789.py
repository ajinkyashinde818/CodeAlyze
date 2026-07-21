import sys

lines = sys.stdin.readlines()
s = [ord(c) - 96 for c in lines[0].strip()]
t = [ord(c) - 96 for c in lines[1].strip()]

def check(s, t):
  if not len(s) and len(t):
    print('Yes')
    return
  elif not len(t) and len(s):
    print('No')
    return
  elif not len(s) and not len(t):
    print('No')
    return
    
  if min(s) < max(t):
    print('Yes')
  elif min(s) > max(t):
    print('No')
  else:
    s.remove(min(s))
    t.remove(max(t))
    return check(s, t)

check(s, t)

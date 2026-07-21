def solve(s):
  while True:
    if s == '':
      return True
    else:
      if s[0:7] == 'dreamer'[::-1]:
        s = s[7:]
      elif s[0:5] == 'dream'[::-1]:
        s = s[5:]
      elif s[0:5] == 'erase'[::-1]:
        s = s[5:]
      elif s[0:6] == 'eraser'[::-1]:
        s = s[6:]
      else:
        return False
  
print('YES' if solve(input()[::-1]) else 'NO')

def check(s: str):
  if len(s) >= 5 and s[-5:] in ['dream', 'erase']:
    return s[:-5]
  elif len(s) >= 6 and s[-6:] in ['eraser']:
    return s[:-6]
  elif len(s) >= 7 and s[-7:] in ['dreamer']:
    return s[:-7]
  return None

s = input()
matched = True
while len(s) > 0:
  s = check(s)
  if s is None:
    matched = False
    break
if matched:
  print('YES')
else:
  print('NO')

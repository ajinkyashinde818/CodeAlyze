s = input()

mojiretu = ['dream','dreamer','erase','eraser']

import re
def setudan(s):
  if s[-5:] == 'dream' or s[-5:] == 'erase':
    return s[:-5]
  elif s[-6:] == 'eraser':
    return s[:-6]
  elif s[-7:] == 'dreamer':
    return s[:-7]
  else:
    return 0

while True:
  s = setudan(s)
  if s == 0:
    print('NO')
    break
  if s =='':
    print('YES')
    break

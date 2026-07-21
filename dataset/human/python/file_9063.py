S = input()

def check(t):
  if len(t) >= 5 and (t[-5:] == 'dream' or t[-5:] == 'erase'):
    return True,t[:-5]
  elif len(t) >=6 and t[-6:] == 'eraser':
    return True,t[:-6]
  elif len(t) >= 7 and t[-7:] == 'dreamer':
    return True,t[:-7]
  else:
    return False,t

while(len(S) > 0):
  flag,S = check(S)
  if not flag:
    print('NO')
    exit()
print('YES')

import sys
s = input()
i = 1 
s1 = ''
while i <= len(s):
  s1 += s[-i]
  i += 1
s2 = s1
while s2 != '':
  if s2[0:5] == 'maerd':
    s2 = s2[5:]
  elif s2[0:7] == 'remaerd':
    s2 = s2[7:]
  elif s2[0:5] == 'esare':
    s2 = s2[5:]
  elif s2[0:6] == 'resare':
    s2 = s2[6:]
  else:
    print('NO')
    sys.exit()
print('YES')

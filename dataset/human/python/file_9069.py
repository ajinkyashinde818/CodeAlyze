import sys
s = input()[::-1]

s_list = ['dream'[::-1], 'dreamer'[::-1], 'erase'[::-1], 'eraser'[::-1]]

while True:
  flag = False
  for l in s_list:
    if s[0:len(l)] == l:
      s = s[len(l):]
      flag = True
  if s == '':
    print('YES')
    sys.exit()
  if flag == False:
    print('NO')
    sys.exit()

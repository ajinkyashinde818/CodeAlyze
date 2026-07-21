import sys


S = input()
length_S = len(S)

cursor_head = 0
cursor_tail = -1

ret = 0

while length_S + cursor_tail > cursor_head:
  if S[cursor_head] == S[cursor_tail]:
    cursor_head += 1
    cursor_tail -= 1
  else:
    if S[cursor_head] == 'x':
      cursor_head += 1
      ret += 1
    elif S[cursor_tail] == 'x':
      cursor_tail -= 1
      ret += 1
    else:
      print(-1)
      sys.exit()
    
print(ret)

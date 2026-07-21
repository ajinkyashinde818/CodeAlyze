from collections import deque
s = input()
tmp = s.replace('x','')
if tmp == tmp[::-1]:
  left = 0
  right = len(s)-1
  result = deque()
  while 1:
    if right == left:
      result.append(s[left])
      break
    if s[left] == s[right]:
      result.appendleft(s[left])
      result.append(s[right])
      left += 1
      right -= 1
    else:
      result.appendleft('x')
      result.append('x')
      if s[left] == 'x':
        left += 1
      else:
        right -= 1
    if right < left:
      break
  print(len(result)-len(s))
else:
  print(-1)

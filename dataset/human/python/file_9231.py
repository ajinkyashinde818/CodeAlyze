s = input()
s = s[::-1]
import re
a = "dream"[::-1]
b = "dreamer"[::-1]
c = "erase"[::-1]
d = "eraser"[::-1]

ans = "YES"
i = 0
while(i<len(s)):
  if s[i:i+5] == a:
    i = i+5
  elif s[i:i+7] == b:
    i = i+7
  elif s[i:i+5] == c:
    i = i+5
  elif s[i:i+6] == d:
    i = i+6
  else:
    ans = "NO"
    break
print(ans)

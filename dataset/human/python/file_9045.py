import re
s = input()
str = ["dream","dreamer","erase","eraser"]
str = ["maerd","remaerd","esare","resare"]
s=s[::-1]
while len(s)>0:
  if len(s) < 5:
    print("NO")
    break
  if s[0:7] == str[1] :
    s=s[7:]
  elif s[0:6] == str[3]:
    s=s[6:]
  elif s[0:5] == str[0] or s[0:5] == str[2]:
    s=s[5:]
  else:
    print("NO")
    break
  if len(s)==0:
    print("YES")
    break

import re

s = input()

s = s[::-1]

while s:
    if re.match("resare",s):
        s = s[6:]
    elif re.match("esare",s):
        s = s[5:]
    elif re.match("remaerd",s):
        s = s[7:]
    elif re.match("maerd",s):
        s = s[5:]
    else:
        break
    
if len(s) == 0:
    print("YES")
else:
    print("NO")

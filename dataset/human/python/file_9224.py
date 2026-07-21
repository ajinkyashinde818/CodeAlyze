s = input()

while s:
   if s[-5:] in ["dream", "erase"]:
      s = s[:-5]
   elif s[-6:] ==  "eraser":
      s = s[:-6]
   elif s[-7:] == "dreamer":
      s = s[:-7]
   else:
      print('NO')
      import sys
      sys.exit()

print('YES')

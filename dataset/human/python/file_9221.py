import sys
s=input()
while(s):
  if(s[-7:]=="dreamer"):
    s=s[:-7]
  elif(s[-5:]=="dream"):
    s=s[:-5]
  elif(s[-6:]=="eraser"):
    s=s[:-6]
  elif(s[-5:]=="erase"):
    s=s[:-5]
  else:
    print("NO")
    sys.exit()
print("YES")

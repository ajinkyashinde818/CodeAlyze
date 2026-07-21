import sys
S = input()
s = S[::-1]
i = 0
n = len(s)-i
while n>0:
  if s[i:i+5] == "maerd" or s[i:i+5] == "esare" :
    i += 5
    n = len(s)-i
  elif s[i:i+6] == "resare":
    i += 6
    n = len(s)-i
  elif s[i:i+7] == "remaerd":
    i += 7
    n = len(s)-i
    pass
  else:
    print("NO")
    sys.exit()
    
print("YES")

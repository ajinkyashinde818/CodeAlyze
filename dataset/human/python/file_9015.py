s=input()[::-1]
n=0
import sys
while n<len(s):
    if s[n:n+5]=="maerd" or s[n:n+5]=="esare":
        n+=5
    elif s[n:n+6]=="resare":
        n+=6
    elif s[n:n+7]=="remaerd":
        n+=7
    else:
        print("NO")
        sys.exit()
print("YES")

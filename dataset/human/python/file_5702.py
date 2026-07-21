import sys
s=input()
b=[]
an=0
for i in range(len(s)):
  if s[i]!="x":
    b.append(s[i])
for i in range(len(b)):
  if b[i]!=b[-i-1]:
    print(-1)
    sys.exit()

i=j=0 
while i<=len(s)-1-j:
  if s[i]==s[-1-j]:
    i+=1
    j+=1
  elif s[i]=="x":
    i+=1
    an+=1
  elif s[-1-j]=="x":
    j+=1
    an+=1

print(an)

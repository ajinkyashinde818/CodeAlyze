import sys
s=list(input())
ct=0
l=0;r=len(s)-1
while l<r:
  if s[l]==s[r]:
    l+=1
    r-=1
  elif s[l]!='x' and s[r]!='x':
    print(-1)
    sys.exit()
  elif s[l]=='x':
    ct+=1
    l+=1
  else:
    ct+=1
    r-=1
print(ct)

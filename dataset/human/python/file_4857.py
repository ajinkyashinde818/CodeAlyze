import sys

s=input()
t=input()
s1,t1="",""

for i in range(len(s)):
  if i!=0:
    if s1[0]>=s[i]:
      s1=s[i]+s1
    
    else:
      s1+=s[i]
      
  else:
    s1=s[i]
    
for i in range(len(t)):
  if i!=0:
    if t1[0]<=t[i]:
      t1=t[i]+t1
    
    else:
      t1+=t[i]
      
    if t1>s1:
      print("Yes")
      sys.exit()
      
  else:
    t1=t[i]
    
print("No")

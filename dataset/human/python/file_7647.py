import sys
input = lambda: sys.stdin.readline().rstrip() 
s=input()
count=0
s1=str()
s2=str()
for _ in range(int(input())):
  l=list(map(str,input().split()))
  
  if l[0]=='1':
    count+=1
  elif count%2==0:
    if l[1]=='1':
      s1=l[2]+s1
    else:
      s2=s2+l[2]
  else:
    if l[1]=='2':
      s1=l[2]+s1
    else:
      s2=s2+l[2]
s=s1+s+s2
if count%2!=0:
  s=s[::-1]
print(s)

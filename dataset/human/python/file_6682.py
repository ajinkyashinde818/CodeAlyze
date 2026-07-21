import sys
s=input()
q=int(input())
a=[]
b=[]
c=0
for i in sys.stdin:
  if '1' in i.split()[0]:
    a,b=b,a
    c+=1
  else:
    if '1' in i.split()[1]:
      a.append(i.split()[2])
    else:
      b.append(i.split()[2])
if c%2==1:
  s=''.join(list(s)[::-1])
print(''.join(a[::-1])+s+''.join(b))

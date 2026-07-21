s=input()
q=int(input())
dir=True
ans=s
right=""
left=""
query=[]
for i in range(q):
  temp=input()
  if temp[0] == "1":
    dir = dir ^ True
  if temp[0] == "2":
    t,f,c = temp.split()

    if (f == "1" and dir) or (f=="2" and not dir):
      left=c+left
    else:
      right=right+c

def reverse(s):
  t=""
  for i in range(len(s)-1,-1,-1):
    t+=s[i]
  return t

if dir:
  print(left+ans+right)
else:
  t=reverse(right)+reverse(ans)+reverse(left)
  print(t)

from sys import stdin as s
init=s.readline().rstrip()
state=1
s1=""
s2=""
q=int(s.readline())
for i in range(q):
  t=s.readline().rstrip()
  if t=="1":
    state=(state+1)%2
  else:
    a,b,c=t.split()
    if int(b)+state==2:
      s1=c+s1
    else:
      s2+=c
ans=s1+init+s2
if state:
  print(ans)
else:
  print(ans[::-1])

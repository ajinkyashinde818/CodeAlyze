s = input()
q = int(input())
t = []
 
def F(f,fr,ba,c):
  if f == '1':
     return c + fr, ba
  if f == '2':
    return fr,ba + c

def R(r):
  if r == '1':return '2'
  if r == '2':return '1'

ans = s
fr = ''
ba = ''
r = '1'
for n in range(q):
  t = input().split()
  if t[0] == '1':
    r = R(r)
  else:
    if r =='2':
      t[1] = R(t[1])
    fr, ba = F(t[1],fr,ba,t[2])
 
    
if r == '1': 
   print(fr + ans + ba)
else:
  print(ba[::-1] + ans[::-1]+ fr[::-1])

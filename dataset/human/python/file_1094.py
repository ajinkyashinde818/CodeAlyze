import sys
input = sys.stdin.readline
 
t = int(input())

a = list(map(int,input().split()))
b = list(map(int,input().split()))

b = b[::-1]

el = -(10**99)
ok = 1

pref, aft = -1,9999999999
pos = set()

for i in range(t):
  if a[i]==b[i]:
    pos.add(i)
    el = a[i]
    ok = 0

for i in range(t):
  if a[i]==el or b[i]==el:
    break
  pref = i
  
for i in range(t):
  if a[i]>el and b[i]!=el:
    aft = i
    break

if ok==1:
  print('Yes')
  print(*b)
  exit()
  
else:
  if len(pos)> 1+pref +(t-aft):
    print('No')
    
  else:
    try:
      for i in range(pref+1):
        x = pos.pop()
        b[i], b[x] = b[x], b[i]

      for i in range(aft,t):
        x = pos.pop()
        b[i], b[x] = b[x], b[i]
    except:
      pass
      
    print('Yes')
    print(*b)

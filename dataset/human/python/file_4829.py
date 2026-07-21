import sys
from string import ascii_lowercase as alph
from itertools import zip_longest

s,t=[list(l) for l in sys.stdin.read().split()]
d=dict((w,x) for w,x in zip(alph,range(26)))
d['?']=-1
s.sort(key=d.get)
t.sort(key=d.get, reverse=True)
for x,y in zip_longest(s,t,fillvalue='?'):
  if d[x]<d[y]:
      print('Yes')
      break
  elif d[x]>d[y]:
      print('No')
      break
else:
  print('No')

def intnum(str):
  n = 0
  if str in range(10):
    n=int(str)
  elif str in {'A'}:
    n=10
  elif str in {'B'}:
    n=11
  elif str in {'C'}:
    n=12
  elif str in {'D'}:
    n=13
  elif str in {'E'}:
    n=14
  elif str in {'F'}:
    n=15
  return n
    

x,y = map(intnum,input().split())
r='='
if x > y:
  r = '>'
elif x < y:
  r ='<'
print(r)

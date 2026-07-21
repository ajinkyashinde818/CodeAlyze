N=int(input())
if N%2==1:
  print(0)
  exit()
def func1(n):
  if n==0:
    return 0
  if n==1:
    return 1
  return 5*func1(n-1)+1
def func(x):
  if x==0:
    return 0
  for i in range(26):
    if x<5**(i+1):
      a=i
      b=x//(5**a)#商
      c=x%(5**a)#あまり
      break
  return b*func1(a)+func(c)
print(func(N//2))

def is_prime(n):
  i=2
  r=[]
  while i*i<=n:
    if n%i==0:
      c=0
      while n%i==0:
        c+=1
        n//=i
      r.append((i,c))
    i+=1
  if n> 1:
    r.append((n,1))
  return r

def main():
  n=int(input())
  r=0
  for p,e in is_prime(n):
    i=1
    while e>=i:
      r+=1
      e-=i
      i+=1
  return r
print(main())

#nの素数判定
# def is_prime(n):
#     if n == 1:
#         return False
#     for i in range(2,int(n**0.5)+1):
#         if n % i == 0:
#             return False
#     return True

# def is_prime(n):
#   i=2
#   table=[]
#   while i*i<=n:
#     while n%i == 0:
#       n//=i
#       table.append(i)
#     i+=1
#   if n>1:
#     table.append(n)
#   return table

# from itertools import groupby
# n=int(input())
# p=is_prime(n)

# ans = 0

# for v, g in groupby(p):
#   n=len(list(g))
#   for i in range(1,100000):
#     n-=i
#     if n>=0:
#       ans+=1
#     else:
#       break
# print(ans)

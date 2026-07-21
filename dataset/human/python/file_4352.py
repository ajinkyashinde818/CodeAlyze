def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(-(-n**0.5//1))+1):
    if temp%i==0:
      cnt=0
      while temp%i==0:
        cnt+=1
        temp //= i
      arr.append(cnt)
  if temp!=1:
    arr.append(1)
  if n==1:
    arr.append(0)
  return arr
def kak(n):
  return ((1+8*n)**(1/2)-1)//2
  
A=factorization(int(input()))
print(int(sum([kak(i) for i in A])))

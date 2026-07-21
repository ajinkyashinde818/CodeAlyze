def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([n, 1])
    return arr
def make_divisors(n):
  lower_divisors,upper_divisors=[],[]
  i=1
  while i*i<=n:
    if n%i==0:
      lower_divisors.append(i)
      if i!=n//i:
        upper_divisors.append(n//i)
    i+=1
  return lower_divisors+upper_divisors[::-1]
N=int(input())
t=make_divisors(N)
u=[]
count=0
if N==1:
  print(0)
else:
  for i in range(1,len(t)):
    if 2>len(factorization(t[i])):
      u.append(t[i])
  for i in range(len(u)):
    if N%u[i]==0:
      N=int(N//u[i])
      count+=1
    if N==1:
      break
  print(count)

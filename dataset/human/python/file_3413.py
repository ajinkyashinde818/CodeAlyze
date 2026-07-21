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
 
t=int(input())
if t==1:
  print(0)
  exit()
 
fac=factorization(t)
 
def pcount(a):
  p=1
  cout=0
  while a>0:
    a=a-p
    p+=1
    if a<0:break
    cout+=1
  return cout
#print(fac)
tt=0
 
for po in fac:
  
  cc=pcount(po[1])
  #print(cc)
  tt+=cc

print(tt)

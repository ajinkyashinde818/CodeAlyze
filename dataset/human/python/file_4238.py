N = int(input())
 
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
 
if N == 1:
  print(0)
  exit()
 
f = factorization(N)

if len(f) == 1 and f[0][1] == 1:
  print(1) 
  exit()

count = 0
num = 1
for p,q in f:
  for e in range(1,q+1):
    if N%p**e == 0:
      N //= p**e
      count += 1
print(count)

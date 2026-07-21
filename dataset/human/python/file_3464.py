from math import sqrt

def is_prime(n):
  if n == 1:
    return False
  for i in range(2, int(sqrt(n))+1):
    if n % i == 0:
      return False
  return True

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(sqrt(n))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
        if len(arr) > 1:
          break

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

base=int(input())
tmp=base
num=[]
if is_prime(base):
  num.append(base)
else:
  for i in range(2, base+1):
    if i > tmp:
      break
    if tmp % i == 0 and len(factorization(i)) == 1:
      num.append(i)
      tmp/=i
      if is_prime(tmp):
        num.append(tmp)
        break
print(len(list(set(num))))

import math
def factorization(n):
    if n == 1:
      return []
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

def ston(s):
  return (-1+math.sqrt(1+8*s))/2

n = int(input())

s = 0
soinsu = factorization(n)
#print(soinsu)
for i in soinsu:
  num = int(ston(i[1]))
  s += num
  
print(s)

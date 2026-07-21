import math

N = int(input())

count = 0

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr
    
soinsu = factorization(N)

def sosu(n):
  if n != 1:
    for i in range(2, int(pow(n, 0.5)) + 1, 1):
      if n % i != 0:
        pass
      else:
  	    break
    else:
      return 1
  	
  return 0

for i in soinsu:
  num = 1
  if sosu(i[0]):
    while 1:
      #print(soinsu, i)
      if i[1] - num >= 0:
        i[1] -= num
        num += 1
        count += 1
      else:
  	    break
  	  
print(count)

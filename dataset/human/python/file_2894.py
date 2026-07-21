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
  
if N <= 1:
  print(0)
else:
  factN = factorization(N)
  counter = 0
  for i in range(len(factN)):
    t = factN[i][1]
    e = 0
    while True:
      t -= e
      if t < 0:
        counter += e - 1
        break
      e += 1
  print(counter)

N = int(input())
 
def prime_factorization(N):
  n = int(N**0.5)+1
  numList = [i if i != 1 else 2 for i in range(1, n, 2) ]
  primeList = [2]
  ansDict = {}
  idx = 0
  for data in numList:
    for x in primeList:
      if (data%x != 0 or x == 2):
        count = 0
        while N%data == 0:
          count += 1
          N //= data
        if count > 0:
          ansDict[data] = count
        if N == 1:
          return ansDict
        if x != 2:
          primeList.append(data)
        break
  if N != 1:
    ansDict[N] = 1
  
  return ansDict 

if N <= 1:
  print(0)
  exit()
  
ansDict = prime_factorization(N)
ansCount = 0
for p,v in ansDict.items():
  e = 1
  while e <= v:
    ansCount += 1
    v -= e 
    e += 1  

print(ansCount)

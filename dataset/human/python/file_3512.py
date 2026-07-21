import math
N = int(input())
rootN  = math.floor(math.sqrt(N))
priFacInd = {}
count = 0
for i in range(2, rootN+1):
  if N % i ==0:
    priFacInd[i] = 0
  while N % i ==0:
    N /= i
    priFacInd[i] += 1
if not N == 1:
  priFacInd[N] = 1
for priFac in priFacInd:
  for i in range(1, rootN+1):
    priFacInd[priFac] -= i
    count += 1
    if priFacInd[priFac] < i+1:
      break
print(count)

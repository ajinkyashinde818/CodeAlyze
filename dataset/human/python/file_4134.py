import collections
N = int(input())
if N < 2:
  print(0)
  exit()

def fact(n):  # O(√N)で素因数のリストを作成　n >= 2

  arr = []
  temp = n

  for i in range(2, int(n**(1/2))+1):
    if temp % i == 0:
      while temp % i == 0:
        temp //= i
        arr.append(i)

  if temp != 1:
    arr.append(temp)

  return collections.Counter(arr)

c = fact(N).most_common()

ans = 0
for i in range(len(c)):
  for j in range(1, 1000):
    if  j*(j-1)//2 <= c[i][1] < j*(j+1)//2:
      ans += j-1
      
print(ans)

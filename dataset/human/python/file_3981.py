import collections
N = int(input())
def prime(N):
  a = []
  while N%2 ==0:
    a.append(2)
    N = N/2
  f = 3
  while f**2 <= N:
    if N%f ==0:
      a.append(f)
      N = N/f
    else:
      f += 2
  if N != 1:
    a.append(int(N))
  return(a)
M = collections.Counter(prime(N))
M_ls = list(M.values())
count = 0
for i in range(len(M_ls)):
  n = 1
  while M_ls[i] >= n*(n+1)/2:
    count += 1
    n += 1
    
print(count)

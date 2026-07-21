import collections

N = int(input())

def f(n) :
  if n < 2 :
    return 1
  else :
    return n * f(n-2)

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

def prime_factorize(n):
  a = []
  while n % 2 == 0:
    a.append(2)
    n //= 2
  f = 3
  while f * f <= n:
    if n % f == 0:
      a.append(f)
      n //= f
    else:
      f += 2
  if n != 1:
    a.append(n)
  return a

if N % 2 != 0 :
  print(0)
else :
  # result = factorization(N)
  result = 0
  tmp = N//5
  # while True : 
  # tmp = collections.Counter(prime_factorize(N))
  # result += tmp[5]
  while True :
    if tmp == 0 :
      break
    result += (tmp//2)
    tmp = tmp//5
  # print(f(N))
  # cnt = 10
  # result = N//cnt
  # cnt *= 10
  # while True :
    # digit = N//cnt
    # if digit == 0 :
    #   break
    # result += digit
    # tmp = cnt
    # while True :
    #   x = tmp // 2
    #   if x == 0 :
    #     break
    #   result += (N//(x))-(N//tmp)
    #   tmp = x
    # cnt *= 10
  # if N >= 50 :
  #   result += (N//50)-(N//100)
  print(result)
  # print(tmp)

N = int(input())

if N == 1:
  print(0)

else:
  def factorization(n):
      arr = []
      temp = n
      for i in range(2, int(-(-n**0.5//1))+1):
          if temp%i==0:
              cnt=0
              while temp%i==0:
                  cnt+=1
                  temp //= i
              arr.append(cnt)

      if temp!=1:
          arr.append(1)

      if arr==[]:
          arr.append(1)

      return arr

  f = factorization(N)
  ans = 0

  for i in range(1,100):
    f = list(map(lambda x:x-i,f))
    ans += len([j for j in f if j >= 0])

  print(ans)

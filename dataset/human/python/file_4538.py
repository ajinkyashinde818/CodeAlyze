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

def check(S):
    if S ==1:
      return 1
    elif S == 2:
      return 1
    elif S == 3:
      return 2
    else:
      for i in range(S):
        if i <= S:
          S -= i
        else:
          return i-1

if N != 1:
  result = factorization(N) 

  a = 0
  for r in result:
    b = check(r[1])
    a += b
  print(a)

else:
  print(0)

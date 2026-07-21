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

if(N == 1):
  print(0)
else:
  result = factorization(N)
  ans = 0
  for i in range(len(result)):
    count = 1
    temp = 0
    while(result[i][1] - count >= 0):
      result[i][1] -= count
      count += 1
      temp += 1
    ans += temp
  print(ans)

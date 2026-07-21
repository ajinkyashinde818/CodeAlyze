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
  
N = int(input())

P = factorization(N)

flag = 0

for i in range(len(P)):
  for j in range(40):
    P[i][1] = P[i][1] - (j + 1)
    if P[i][1] >= 0:
      flag += 1
    else:
      break
if N == 1:
  print(0)
else:
  print(flag)

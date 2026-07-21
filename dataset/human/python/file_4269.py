n = int(input())

if n == 1:
  print(0)
  exit()

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

F = factorization(n)

cnt = 0 
for i in range(len(F)):
  m = 1
  while F[i][1] >= m*(m+1)/2:
    cnt += 1
    m += 1

print(cnt)

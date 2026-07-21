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
A  = factorization(N) 

count = 0
for i in A:
  judge = 1
  temp = i[1]
  while temp >= judge:
    count += 1
    temp -=judge
    judge += 1

if N == 1:
  count = 0

print(count)

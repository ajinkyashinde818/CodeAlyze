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

cnt = 0
n = int(input())
#if n == 1:
#  print(0)

f_list = factorization(n)

for item in f_list:
  power = item[1]
  counter = 1
  while(True):
    power -= counter
    if power<0:
      break
    cnt+=1
    counter+=1
if n == 1:
  cnt = 0
print(cnt)

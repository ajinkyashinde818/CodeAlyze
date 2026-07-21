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

n = int(input())
prime_factors = factorization(n)
# print(prime_factors)

if n == 1:
  print(0)
  exit()

counter = 0
for factor in prime_factors:
  factor_num = factor[1]
  power = 1
  while factor_num - power >= 0:
    factor_num -= power
    counter += 1
    power += 1

print(counter)

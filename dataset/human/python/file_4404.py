import math

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(math.ceil(n**0.5))):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i,cnt])
    
    if temp != 1:
        arr.append([temp, 1])
    
    if arr == []:
        arr.append([n, 1])

    return arr

n = int(input())
if n == 1:
    print(0)
    exit(0)

fact_1i = factorization(n)

res = 0
for _, num in fact_1i:
    temp_num = 1
    while temp_num <= num:
        res += 1
        num -= temp_num
        temp_num += 1

print(res)

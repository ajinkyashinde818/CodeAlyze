import math
n = int(input())

def prime(n):
    factor = {}
    tmp = int(math.sqrt(n)) + 1
    for num in range(2, tmp):
        while n % num == 0:
            n //= num
            if not num in factor.keys():
                factor[num] = 1
            else:
                factor[num] += 1
        if num > n:
            break
    if n != 1:
        if not n in factor.keys():
            factor[n] = 1
        else:
            factor[n] += 1
    return factor

#print(prime(n))

ans = 0

#dic = {}
pr = prime(n)
for num, count in pr.items():
    tmp = count
    ini = 1
    while tmp > 0:
        tmp -= ini
        if tmp < 0:
            break
        ini += 1
        ans += 1
    #print(ans,num,tmp)

print(ans)

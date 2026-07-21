from math import log
n = int(input())


def make_divisors(n):
    lower_divisors, upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]


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


yakusu_list = make_divisors(n)
ans_list = []
# print(yakusu_list)
ans = 0
for r in yakusu_list:
    if r == 1:
        continue
    if len(factorization(r)) == 1 and n % r == 0:
        n //= r
        ans += 1
        ans_list.append(r)
    if n == 1:
        break
# print(ans_list)
print(ans)

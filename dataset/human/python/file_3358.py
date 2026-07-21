from math import sqrt, ceil

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

def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

ans = 0
search_list = make_divisors(N)[1:]
if (N > 1) and (N not in search_list):
    search_list.append(N)

for i in search_list:
    if N%i == 0:
        fact = factorization(i)
        if len(fact) == 1:
            N = N // i
            if N >= 1:
                ans += 1
            else:
                break

print(ans)

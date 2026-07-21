from collections import Counter

def Eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

n = int(input())
n2 = n

if n == 1:
    print(0)
    exit()

prime_factors = [] #素因数
for i in Eratosthenes(int(n ** 0.5)):
    if i**2 > n2:
        break
    while n2 % i == 0:
        prime_factors.append(i)
        n2 //= i
if n2 > 1:
    prime_factors.append(n2)

#↑までで素因数分解

cntr = Counter(prime_factors)
cnt = 0
#for k, v in cntr.items():
for v in cntr.values():
    sisuu = v
    sub = 1
    while sisuu - sub >= 0:
        sisuu -= sub
        cnt += 1
        sub += 1
print(cnt)
"""
ans = []
list = []
for i in prime_factors:
    for j in list:
        if j % i == 0:
            tmp = list.pop(list.index(j)) * i
            if tmp in ans:
                list.append(tmp)
                continue
            ans.append(tmp)
    if i in list:
        tmp = list.pop(list.index(i)) * i
        if tmp in ans:
            list.append(tmp)
            continue
        ans.append(tmp)
    elif i in ans:
        list.append(i)
    else:
        ans.append(i)

print(len(ans))
"""

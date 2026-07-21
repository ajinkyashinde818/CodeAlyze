import math
def primeFactors(n):
    pri = []
    while n % 2 == 0:
        pri.append(2)
        n = n // 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            pri.append(i)
            n = n // i
    if n > 2:
        pri.append(n)
    return pri
n = int(input())
if n==1:
    print(0)
    exit(0)
fact = set()
for i in range(2,int(n**0.5)+1):
    if n%i==0:
        fact.add(i)
        fact.add(n//i)
fact.add(n)
fact = sorted(fact)
cnt = 0
for i in fact:
    p = primeFactors(i)
    if p.count(p[0])==len(p):
        if n%i==0:
            n//=i
            # print(i, n)
            if n >= 1:
                cnt += 1
            else:
                break
print(cnt)

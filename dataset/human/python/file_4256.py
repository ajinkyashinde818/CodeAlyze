import math 
def primeFactors(n):
    pf = []
    while n % 2 == 0: 
        pf.append(2) 
        n = n / 2 
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            pf.append(i) 
            n = n / i 
    if n > 2: 
        pf.append(n) 
    return pf
n = int(input())
pf = primeFactors(n)

dic = {}
for i in pf:
    try:
        dic[i] += 1
    except:
        dic[i] = 1
ans = 0
for i in dic:
    c = dic[i]
    tmp = (((1 + 8 * c) ** (0.5)) - 1) // 2
    ans += tmp
print(int(ans))

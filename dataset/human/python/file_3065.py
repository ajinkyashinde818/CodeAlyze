import math
n=int(input())
def factorization(num):
    factor = []
    flag = True
    is_Prime= True
    if num == 1:
        is_Prime = False
    while num > 1 and flag:
        flag = False
        for i in range(int(math.sqrt(num))+2):
            k = i + 2
            if num % k == 0:
                factor.append(k)
                num = int(num / k)
                is_Prime = False
                flag = True
                break
    if is_Prime or num > 1:
        factor.append(num)
    return factor
a = factorization(n)
from collections import Counter
co = Counter(a)
result = 0
for k, num in co.items():
    c = 0
    for i in range(1, num+1):
        c += i
        result += 1
        if c > num:
            result -= 1
            break
print(result)

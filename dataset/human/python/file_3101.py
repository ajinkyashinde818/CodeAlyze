import collections
import numpy as np
num =  int(input())
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
c = collections.Counter(prime_factorize(num))
ln = np.array(list(c.values()) )# 各素因数の乗数
#print('ln = ', ln )
minus = 1
number = 0
#print(number)
if len(ln) == 0:
    ln = [-1]
    
while max(ln) >= 0:
    ln = ln - minus
    #print(ln)
    for i in range(len(ln)):
        if ln[i] >= 0:
            number += 1
    
    minus += 1
print(number)

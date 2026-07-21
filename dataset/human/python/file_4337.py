N=int(input())

def prime_factorize(n):
    a=[]
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f* f <= n:
        if n %f == 0:
            a.append(f)
            n //= f
        else:
            f+=2
    if n != 1:
        a.append(n)
    return a

num_list = prime_factorize(N)

from collections import defaultdict
d = defaultdict(int)

for key in num_list:
    d[key] += 1

cnt = 0
for key,value in d.items():
    for i in range(1,value+1):
        if value-i >= 0:
            cnt+=1
            value -= i
            
print(cnt)

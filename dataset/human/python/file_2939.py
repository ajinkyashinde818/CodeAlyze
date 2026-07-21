import math
n = int(input())
prime = []
insu = {}
max_itr = math.ceil(math.sqrt(n))+1
try_range = [2] + list(range(3, max_itr, 2))
for i in try_range:
    if i > max_itr:
        break
    if n%i == 0:
        flag = 0
        for p in prime:
            if i%p == 0:
                flag = 1
                break
        if flag == 0:
            prime.append(i)
            while n%i == 0:
                if i in insu:
                    insu[i] += 1
                else:
                    insu[i] = 1
                n //= i
            if n < max_itr:
                max_itr = n

if n != 1:
    insu[n] = 1
# print(insu)

count = 0
for v in insu.values():
    i = 1
    while v >= i:
        v -= i
        i += 1
        count += 1

print(count)

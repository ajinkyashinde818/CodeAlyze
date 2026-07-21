from math import ceil, sqrt

n = int(input())

p_map= {}
for i in range(2, ceil(sqrt(n))+1):
    while n % i == 0:
        n /= i
        if i not in p_map:
            p_map[i] = 1
        else:
            p_map[i] += 1
if n > 2:
    p_map[n] = 1

res = 0
for i, v in p_map.items():
    prev = 0
    for i in range(1, 41):
        current = prev+1
        if v < current:
            break
        v -= current
        res += 1
        prev = current
print(res)

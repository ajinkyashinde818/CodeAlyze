import collections
n = int(input())
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
a = collections.Counter(a)

count = 0
for i in a.values():
    for j in range(1,1000000):
        if i - j >= 0:
            count += 1
            i -= j
        else:
            break
print(count)

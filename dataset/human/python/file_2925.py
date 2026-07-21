import math

n = int(input())
count = 0
p = n

for z in range(2, int(math.sqrt(n)) + 1):
    e = 1
    while n % z ** e == 0:
        n //= z ** e
        count += 1
        e += 1
    if n % z == 0: #これを行わなければ，素因数同士でかける場合も含んでしまう．
        while n % z == 0:
            n //= z

if n != 1:
    count += 1
if count == 0 and p != 1:
    count = 1

print(count)

import math

n = int(input())
divs = []
for i in range(1, int(math.sqrt(n)) + 1):
    if n % i == 0:
        j = n // i
        if i != j:
            divs.append(j)
        divs.append(i)
divs.sort()

m = len(divs)
ans = 0
for i in range(1, m):
    z = divs[i]
    z2 = z
    prime = True
    for j in divs[1:i]:
        if z2 % j == 0:
            while z2 % j == 0:
                z2 //= j
            if z2 != 1:
                prime = False
    if prime:
        if n % z == 0:
            n //= z
            ans += 1
print(ans)

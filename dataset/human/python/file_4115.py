from math import sqrt

n = int(input())

i = 2

c = []

while i*i <= n:
    j = 0
    while n%i == 0:
        j += 1
        n //= i   
    else:
        if j != 0:
            c.append(j)
    i += 1
if n > 1:
    c.append(1)
             
d = 0        
if c == []:
    print(d)
else:
    for k in c:
        d += int((sqrt(1 + 8*k)-1)/2)
    print(d)

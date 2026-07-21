import math
n = int(input())
a = []
b= []
while n % 2 == 0:
    b.append(2)
    n //= 2
if(len(b)!= 0):
    a.append(b)
    b= [] 
f = 3
while f * f <= n:

    if n % f == 0:
        b.append(f)
        n //= f
    else:
        f += 2
        if(len(b)!= 0):
            a.append(b)
            b= [] 

if(len(b)!= 0):
        a.append(b)
        b= [] 
if(len(a) != 0):
    if(n == a[len(a)-1][0]):
        a[len(a)-1].append(n)
        n  = 1
if (n != 1 ):
    b.append(n)
    a.append(b)

ans =0
for i in range(len(a)):
    ans += int((-1 + math.sqrt(1 + 8 * len(a[i])))/2)

print(ans)

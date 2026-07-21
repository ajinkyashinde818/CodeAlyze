import math
r,g,b,n = map(int,input().split())

max_r, max_g = math.floor(n/r),math.floor(n/g)

c = 0
for i in range(max_r+1):
    for j in range(max_g+1):
        b_n = n - (i*r) - (j*g)
        if b_n < 0:
            continue
        if b_n % b == 0:
            c += 1

print(c)

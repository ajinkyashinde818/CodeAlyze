import math

r, g, b, n = map(int, input().split())
ball = [0, r, g, b]
count = 0

for i in range(n+1):
    for j in range(n+1):
        m = math.floor((n-i*r-j*g)/b)
        if i*r+j*g+m*b == n and m >= 0:
            count += 1
            
print(count)

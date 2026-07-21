import math as ma
N = int(input())
a = list(map(int, input().split()))
s = sum(a)
A = 0
diff = 9999999999
for i in range(N-1):
    A += a[i]
    if diff > (ma.fabs(2*A - s)):
        diff = ma.fabs(2*A -s)
print(int(diff))

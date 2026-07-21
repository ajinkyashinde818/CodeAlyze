import math

n = int(input())
x = list(map(int,input().split()))

mod = 10**9 + 7

f = math.factorial(n-1)
f %= mod

def modinv(a, mod=10**9+7):
    return pow(a, mod-2, mod)

l = []
for i in range(n-1):
    d = x[i+1] - x[i]
    l.append(d)

# print(l)

count = 0
k = f
plus = 0
for i in range(1,n):
    # print(k)
    k = f + plus
    count += l[i-1] * k
    plus += f * modinv(i+1,mod)

print(int(count)%mod)

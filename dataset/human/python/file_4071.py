import math

N = int(input())

A_max = int(math.sqrt(N) + 1)
A = list(range(2, A_max))

prime_check = [0] * (A_max + 1)
multi_list = []

def multi_x(X, n):
    i = 1
    result = 0
    while X % (n**i) == 0:
        result = i
        i += 1
    return result

for a in A:
    if prime_check[a] == 0:
        i = 2
        x = multi_x(N, a)
        if x != 0:
            multi_list.append(x)
            N = N // a**x
        while a * i <= A_max:
            prime_check[a * i] = 1
            i += 1

if N > A_max:
    ans = 1
else:
    ans = 0

for m in multi_list:
    i = 1
    buf = m
    while buf >= i:
        buf -= i
        i += 1
        ans += 1

print(ans)

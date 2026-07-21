N = int(input())

ans = 0

def prime_factorize(n):
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
    return set(a)

prime_list = prime_factorize(N)

# 通ったやつ
# if prime_list:
#     for prime_num in prime_list:
#         if N % prime_num == 0:
#             for j in range(1, 100):
#                 if N < prime_num**j:
#                     break
#                 if N % prime_num**j == 0:
#                     N //= prime_num**j
#                     ans += 1

# 通ってないやつ
if prime_list:
    for prime_num in prime_list:
        if N % prime_num == 0:
            i = 1
            while N % prime_num**i == 0:
                N //= prime_num**i
                ans += 1
                i += 1


print(ans)

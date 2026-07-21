import collections

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
    return a
c = collections.Counter(prime_factorize(int(input())))
# c = prime_factorize(int(input()))
a = 0
# print(c)
for i in c.values():
    # print(i)
    x = 1
    while i > 0:
        i -= x
        a += 1
        x += 1
        # print(i,x,a)
        if i < 0 :
            a -= 1

# a,z = 0,0
# for i in c:
#     if z == i :
#         z = 0
#     else :
#         z = i
#         a += 1
print(a)

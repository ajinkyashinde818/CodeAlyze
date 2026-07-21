import collections
n = int(input())
arr = collections.Counter()
def factorize(num):
    while num % 2 == 0:
        arr[2] += 1
        num //= 2
    f = 3
    while f ** 2 <= n:
        if num % f == 0:
            arr[f] += 1
            num //= f
        else:
            f += 2
    if num != 1:
        arr[num] = 1

factorize(n)
varr = list(arr.values())
ans = 0
for i in varr:
    c = 0
    while c < i:
        ans += 1
        c += 1
        i -= c
print(ans)

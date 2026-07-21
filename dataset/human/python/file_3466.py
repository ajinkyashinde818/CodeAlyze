import sys


def I(): return int(sys.stdin.buffer.readline())


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


n = I()
if n == 1:
    print(0)
    sys.exit()

# 素因数分解
facts = factorization(n)
# print(facts)
ans = 0
for prime, e in facts:
    # print(f'{prime=}')
    i = 1
    while e > 0:
        # print(f'while内 {e=}, {i=}, {ans=}')
        if e - i < 0:
            break
        e -= i
        ans += 1
        # print(f'加算{ans=}')
        i += 1
print(ans)

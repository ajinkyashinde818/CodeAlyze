import sys
sys.setrecursionlimit(100000)


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5 // 1)) + 1):
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


elements = set()


def decomposition(used_set, last_used, rest):
    global elements

    if rest == 0:
        if len(used_set) > len(elements):
            elements = used_set
    i = last_used + 1
    while rest - i >= 0:
        if i in used_set:
            continue
        decomposition(used_set | {i}, i, rest - i)
        i += 1


N = int(input())
if N == 1:
    print(0)
    exit()
factors = factorization(N)
ans = 0
for p, e in factors:
    if e == 2:
        ans += 1
    else:
        elements = set()
        decomposition({1}, 1, e - 1)
        ans += len(elements)
print(ans)

n = int(input())
s = list(input())
mod = 10 ** 9 + 7

if s[0] != "B" or s[-1] != "B":
    print(0)
    exit()

d = {"B": "W", "W": "B"}


def flip(x):
    return d[x]


lr = [1]
for i in range(1, 2 * n):
    if s[i-1] == s[i]:
        lr.append(0)
        s[i] = flip(s[i])
    else:
        lr.append(1)

if sum(lr) != n:
    ans = 0

else:
    l_cnt = 0
    ans = 1
    for e in lr:
        if e:
            l_cnt += 1
        else:
            ans *= l_cnt
            ans %= mod
            l_cnt -= 1

    for i in range(1, n + 1):
        ans *= i
        ans %= mod

print(ans)

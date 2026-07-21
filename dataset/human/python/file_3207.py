N = int(input())


def sb(n):
    if n == 1:
        return {1: 0}
    else:
        dic = {}
        tmp = n
        for i in range(2, int(n ** 0.5) + 1):
            if tmp % i == 0:
                dic[i] = 0
                while tmp % i == 0:
                    dic[i] += 1
                    tmp //= i

        if tmp != 1:
            dic[tmp] = 1

        if dic == {}:
            dic[n] = 1

        return dic


ans = 0

for key in sb(N):
    v = sb(N)[key]
    dv = 1
    while v - dv >= 0:
        v -= dv
        dv += 1
        ans += 1

print(ans)

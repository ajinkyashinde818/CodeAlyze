n = int(input())

def factrization(m):
    temp = m
    ans = 0
    for i in range(2, int(n**0.5) + 1):
        if temp % i == 0:
            cnt = 0
            e = 1
            while temp % i == 0:
                cnt += 1
                temp //= i
                if cnt == e:
                    e += 1
                    cnt = 0
                    ans += 1

    if temp != 1:
        ans += 1

    return ans

print(factrization(n))

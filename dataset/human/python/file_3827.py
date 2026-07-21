def make_divisors(n):
    divisors = {}
    tmp = n
    for div in range(2, int(n**0.5)+1):
        if n % div == 0:
            divisors[div] = 0
        while n % div == 0:
            n //= div
            divisors[div] += 1
        div += 1
    if n > 1:
        divisors[n] = 1
    return divisors

def resolve():
    n = int(input())
    div = make_divisors(n)
    ans = 0
    for k,v in div.items():
        cnt = 1
        while v >= cnt:
            ans += 1
            v -= cnt
            cnt += 1
    print(ans)


if __name__ == "__main__":
    resolve()

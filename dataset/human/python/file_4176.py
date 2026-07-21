def main():
    n = int(input())
    dic = {}
    x = 2
    while n % x == 0:
        if x in dic:
            dic[x] += 1
        else:
            dic[x] = 1
        n //= x
    x = 3
    while x**2 <= n:
        while n % x == 0:
            if x in dic:
                dic[x] += 1
            else:
                dic[x] = 1
            n //= x
        x += 1
    if n > 1:
        if n in dic:
            dic[x] += 1
        else:
            dic[x] = 1
    ans = 0
    for v in dic.values():
        p = 1
        while p <= v:
            ans += 1
            v -= p
            p += 1
    print(ans)

if __name__ == "__main__":
    main()

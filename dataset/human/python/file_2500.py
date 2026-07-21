def main():
    d,g = (int(x) for x in input().split())
    g //= 100
    pc = []
    for _ in range(d):
        p,c = (int(x) for x in input().split())
        pc.append((p,c // 100))

    ans = 10**10
    for i in range(1 << d):
        cnt, total = 0, 0
        max = -1
        for j in range(d):
            if (i >> j) & 1:
                p,c = pc[j]
                cnt += p
                total += c + p * (j + 1)
            else:
                max = j + 1

        if  total < g:
            rem = (g - total + max - 1) // max
            if rem >= pc[max - 1][0]:
                continue
            cnt += rem

        ans = min(ans, cnt)

    print(ans)

if __name__ == '__main__':
    main()

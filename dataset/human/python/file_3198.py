def main():
    from collections import Counter as ct
    n = int(input())

    def soinsuu(a):
        yy, j = [], 2
        y = yy.append
        while(a > 1):
            for i in range(j, int(a**0.5)+1):
                if a % i == 0:
                    y(i)
                    a, j = a//i, i
                    break
            else:
                y(a)
                break
        yy.sort()
        return yy
    s = ct(soinsuu(n))
    cnt = 0
    for i, j in s.items():
        for k in range(1, 10**5):
            if j >= k:
                j -= k
                cnt += 1
            else:
                break
    print(cnt)


main()

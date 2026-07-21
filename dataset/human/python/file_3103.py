def factorization(n):
    arr = []
    tmp = n
    for i in range(2, int(n ** 0.5)):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                cnt += 1
                tmp //= i
            arr.append(cnt)
    if tmp != 1:
        arr.append(1)

    if not arr:
        arr.append(1)

    return arr


def main():
    n = int(input())
    if n == 1:
        print(0)
    else:
        arr = factorization(n)
        cnt = 0
        for e in arr:
            if 1 <= e < 3:
                cnt += 1
            elif 3 <= e < 6:
                cnt += 2
            elif 6 <= e < 10:
                cnt += 3
            elif 10 <= e < 15:
                cnt += 4
            elif 15 <= e < 21:
                cnt += 5
            elif 21 <= e < 28:
                cnt += 6
            elif 28 <= e < 36:
                cnt += 7
            elif 36 < e:
                cnt += 8
        print(cnt)


if __name__ == '__main__':
    main()

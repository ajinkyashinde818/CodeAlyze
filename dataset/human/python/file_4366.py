def factorization(n: int) -> list:
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


def main():
    n = int(input())
    if n == 1:
        print(0)
        return
    factors = factorization(n)
    ans = 0

    for _, e in factors:
        ei = 1
        while ei <= e:
            e -= ei
            ei += 1
            ans += 1

    print(ans)


if __name__ == '__main__':
    main()

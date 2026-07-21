def is_prime(num:int):
    if num == 1:
        return False
    elif num == 2:
        return True
    elif num % 2 == 0:
        return False

    r_num = int(num ** 0.5)
    for i in range(3, r_num + 1, 2):
        if num % i == 0:
            return False
    return True


def main():
    n = int(input())

    if n == 1:
        print(0)
        return

    cnt = 0
    r_n = int(n ** 0.5)
    divided = []
    for i in range(2, n):
        if n < i:
            break
        elif cnt == 0 and r_n+1 < i:
            break
        if n % i == 0 and is_prime(i):
            n = int(n/i)
            divided.append(i)
            cnt += 1
            x = 2
            while True:
                q = i ** x
                if q > n:
                    break

                if n % q == 0:
                    n = int(n/q)
                    x += 1
                    cnt += 1
                else:
                    break
            if is_prime(n) and n not in divided:
                n = 1
                cnt += 1
                break

    if cnt == 0:
        cnt = 1
    print(cnt)


main()

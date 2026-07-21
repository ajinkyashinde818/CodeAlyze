def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


def q4():
    N = int(input())
    arr = prime_factorize(N)
    if not arr:
        print(0)
        return

    ans_count = 0
    count = 1

    min_val = min(arr)
    while arr:
        if arr.count(min_val) < count:
            arr = list(filter(lambda a: a != min_val, arr))
            count = 1
            if not arr:
                break
            min_val = min(arr)
            continue
        arr = arr[count:]
        ans_count += 1
        count += 1
    print(ans_count)


q4()

N = int(input())


def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        j = 0
        while n % i == 0:
            n /= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table


if N == 1:
    print(0)
else:
    table = prime_decomposition(N)
    temp = list(set(table))

    count = 0
    for i in range(len(temp)):
        c = table.count(temp[i])
        k = 1
        while c > 0:
            c -= k
            k += 1
            if c >= 0:
                count += 1

    print(count)

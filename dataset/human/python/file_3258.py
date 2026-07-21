def factorization(n):
    factorization_list = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            count = 0
            while temp % i == 0:
                count += 1
                temp //= i
            factorization_list.append([i, count])

    if temp != 1:
        factorization_list.append([temp, 1])

    if factorization_list==[]:
        factorization_list.append([n, 1])

    return factorization_list


if __name__ == "__main__":
    N = int(input())

    if N == 1:
        print(0)

    else:
        factorization_list = factorization(N)
        count = 0
        for factor in factorization_list:
            e = factor[1]
            i = 1
            while True:
                e -= i
                i += 1
                count += 1
                if e < i:
                    break
        print(count)

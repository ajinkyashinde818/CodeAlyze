def resolve():
    N = int(input())

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

    a = prime_factorize(N)

    count_dict = {}
    total_key = 0
    for i in range(1024):
        total_key += i
        for j in range(total_key-i, total_key):
            count_dict[j] = i-1

    a_element_counter = {}
    for i in a:
        if i not in a_element_counter:
            a_element_counter[i] = 0
        a_element_counter[i] += 1

    ans = 0
    for e in a_element_counter.values():
        ans += count_dict[e]
    print(ans)

if __name__ == "__main__":
    resolve()

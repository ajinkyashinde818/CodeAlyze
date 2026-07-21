def factorization(n):
    index = []
    num = n
    for i in range(2, int(n ** 0.5 + 1)):
        if num % i == 0:
            c = 0
            while num % i == 0:
                c += 1
                num //= i
            index.append(c)

    if num != 1:
        index.append(1)

    if index == []:
        index.append(-1)

    return index

def main():
    n = int(input())
    a = factorization(n)
    ans = 0
    for i in a:
        for j in range(1, 45):
            if i >= j:
                i -= j
                ans += 1
            else:
                break
    print(ans)

main()

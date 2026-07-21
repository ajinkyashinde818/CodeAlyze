def main():
    n = int(input())
    if n == 1:
        print(0)
        return
    def eratos(n):
        flag = [True] * (n + 1)
        for i in range(2, int(n**0.5) + 1):
            if flag[i]:
                for j in range(2*i, n + 1, i):
                    flag[j] = False
        return [i for i, x in enumerate(flag) if x and i >= 2]
    p = eratos(10**6)
    work = []
    for i in p:
        piyo = 0
        while n % i == 0:
            n //= i
            piyo += 1
        if piyo > 0:
            work.append(piyo)
        if n == 1:
            break
    if len(work) == 0:
        print(1)
        return
    else:
        result = 0
        for i in work:
            for j in range(1, 10**6):
                i -= j
                if i <0:
                    break
                result += 1
    if n != 1:
        result += 1
    print(result)
main()

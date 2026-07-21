def main():
    def factorization(n):
        arr = []
        tmp = n
        for i in range(2, int(-(-tmp**0.5//1))):
            if tmp%i == 0:
                cnt = 0
                while tmp%i == 0:
                    cnt += 1
                    tmp //= i
                arr.append([i, cnt])
        if tmp != 1:
            arr.append([tmp, 1])
        if tmp == []:
            arr.append([n, 1])
        return arr
    n = int(input())
    fn = factorization(n)
    x = [fn[i][1] for i in range(len(fn))]
    b = 1
    res = 0
    for i in x:
        while b <= i:
            i -= b
            b += 1
            res += 1
        b = 1
    print(res)   

if __name__ == '__main__':
    main()

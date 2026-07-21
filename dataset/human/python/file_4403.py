def d_div_game():
    def prime_factorization(n):
        """n を素因数分解したときの素数とその指数の辞書"""
        from collections import defaultdict
        if n == 1:
            return {2: 0}  # 1 は素数の 0 乗の積とみなす
        i, table = 2, defaultdict(int)
        while i**2 <= n:
            while n % i == 0:
                table[i] += 1
                n //= i
            i += 1
        if n > 1:
            table[n] = 1
        return table

    def sub(n):
        """1 + ... + e = e*(e+1)//2 <= n となる最大の e を返す"""
        for e in range(1, n + 2):
            if e * (e + 1) > 2 * n:  # e = n + 1 は必ずこの不等式を満たす
                return e - 1

    return sum(sub(v) for v in prime_factorization(int(input())).values())

print(d_div_game())

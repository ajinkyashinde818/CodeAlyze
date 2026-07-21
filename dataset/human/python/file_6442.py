N = int(input())

def df(n):
    if n == 0 or n == 1:
        return 0
    elif n % 2 == 1:
        return 0
    else:
        memo = {}
        ans = 0
        def calc(x):
            if x == 0:
                return 0
            if x not in memo:
                memo[x] = calc(x - 1) * 5 + 1
            return memo[x]

        while n >= 50:
            x = n // 2
            c = 0
            while x >= 5:
                x /= 5
                c += 1
            ans += calc(c)
            n -= 5 ** c * 2
        ans += n // 10
        return ans

print(df(N))

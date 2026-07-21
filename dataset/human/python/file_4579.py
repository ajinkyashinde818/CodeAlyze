import math




def solve(n):
    ans = 0
    for i in range(2, int(math.sqrt(n) + 2)):
        if n % i == 0:
            times = 0
            needed = 1
            while n % i ==0:
                times += 1
                if times>= needed:
                    times = 0
                    needed += 1
                    ans += 1
                n //= i
    if not n == 1:
        print(ans+1)
    else:
        print(ans)
    return



n = int(input())
solve(n)

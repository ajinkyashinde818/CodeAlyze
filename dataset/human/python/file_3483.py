from collections import Counter
from bisect import bisect_right

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



def main():
    N = int(input())

    nums = [0] * 42
    nums[1] = 1
    for i in range(1, 41):
        nums[i+1] = nums[i] + (i+1)
    
    factor = prime_factorize(N)
    c = Counter(factor)
    ans = 0

    for val in c.values():
        idx = bisect_right(nums, val)
        ans += idx - 1
    print(ans)

if __name__ == "__main__":
    main()

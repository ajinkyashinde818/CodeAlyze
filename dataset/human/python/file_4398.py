import sys
from collections import Counter
 
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60

def prime_factorize(x):
    a = []
    while x % 2 == 0:
        a.append(2)
        x //= 2
    f = 3
    while f * f <= x:
        if x % f == 0:
            a.append(f)
            x //= f
        else:
            f += 2
    if x != 1:
        a.append(x)
    return a

def main():
    N = int(readline())
    a = Counter(prime_factorize(N))
 
    ans = 0
    for power in a.values():
        ans += int(((1 + 8 * power) ** 0.5 - 1) / 2)
 
    print(ans)
    return
 
 
if __name__ == '__main__':
    main()

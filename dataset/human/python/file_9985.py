import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def gcd(m, n):
    r = m % n
    return gcd(n, r) if r else n


def lcm(m, n):
    return m // gcd(m, n) * n


a, b = map(int, readline().split())
print(lcm(a,b))

import sys
sys.setrecursionlimit(100001)

def gcd(a, b):
    if a == b:
        return a
    elif a == 0:
        return b
    elif b == 0:
        return a
    else:
        if a > b:
            a = a % b
            return gcd(a, b)
        else:
            b = b % a
            return gcd(a, b)

A, B = [int(n) for n in input().split()]

s = A * B // gcd(A, B)

print(s)

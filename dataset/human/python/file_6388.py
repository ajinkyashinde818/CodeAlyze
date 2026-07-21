import sys
import math
import re
import io

def query(n, m):
    ans = 0
    while n > 0:
        ans += n // m
        n //= m
    return ans

def solve(n):
    if n < 2:
        return 0
    if n % 2 == 0:
        return query(n // 2, 5)
    return 0

def main():
    n = int(input())
    ans = solve(n)
    print(ans)

if __name__ == "__main__":
    main()

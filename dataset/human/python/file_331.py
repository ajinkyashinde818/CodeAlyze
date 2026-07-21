import sys
from functools import reduce

def main():
    input = sys.stdin.readline
    N = int(input())
    As = list(map(int, input().split()))
    sign = reduce(lambda x, y: x * y, [int(a >= 0) * 2 - 1 for a in As])
    A_abs = [abs(a) for a in As]
    ans = sum(A_abs) if sign > 0 else sum(A_abs) - 2 * min(A_abs)
    print(ans)

if __name__ == '__main__':
    main()

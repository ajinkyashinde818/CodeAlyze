import sys
import numpy as np

readline = sys.stdin.readline

def main():
    N = int(input())
    A = list(map(int, readline().split()))

    base0 = A[0]
    base1 = sum(A) - base0

    ans = abs(base1 - base0)

    for i in range(1,N-1):
        base0 += A[i]
        base1 -= A[i]
        ans = min(abs(base1 - base0), ans)

    print(ans)


if __name__ == "__main__":
    main()

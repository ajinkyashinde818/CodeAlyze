import sys
from itertools import accumulate
def input(): return sys.stdin.readline().strip()


def main():
    N = int(input())
    A = list(map(int, input().split()))
    S = list(accumulate(A))
    minimum = 10**18
    for i, c in enumerate(S):
        if i == N - 1: continue
        minimum = min(minimum, abs(2 * c - S[-1]))
    print(minimum)

if __name__ == "__main__":
    main()

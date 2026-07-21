import sys
from itertools import accumulate

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    B = list(accumulate(A))

    total = sum(A)
    ans = float('inf')
    for b in B[:N-1]:
        ans = min(ans, abs((total - b) - b))

    return ans



if __name__ == '__main__':
    print(main())

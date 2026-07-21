from itertools import accumulate
import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    r = 0
    for i in range(N):
        r += B[A[i] - 1]
        if i < N - 1 and A[i+1] - A[i] == 1:
            r += C[A[i] - 1]
    print(r)


if __name__ == '__main__':
    main()

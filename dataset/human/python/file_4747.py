import sys
import os

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))
fl = lambda: list(map(float, sys.stdin.buffer.readline().split()))
iln = lambda n: [int(sys.stdin.buffer.readline().rstrip()) for _ in range(n)]

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
sl = lambda: list(map(str, sys.stdin.buffer.readline().decode().split()))
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    A = list(iss())
    B = list(iss())
    A.sort()
    B.sort(reverse=True)
    print('Yes' if ''.join(A) < ''.join(B) else 'No')


if __name__ == '__main__':
    main()

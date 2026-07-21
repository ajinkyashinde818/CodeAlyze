import sys
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')
in_map = lambda: [s == ord('.') for s in read() if s != ord('\n')]


def main():
    N, M = in_nn()
    t = in_map()
    A = np.array(t[:N * N]).reshape(N, N)
    B = np.array(t[N * N:]).reshape(M, M)

    ans = 'No'
    for y in range(N - M + 1):
        for x in range(N - M + 1):
            if np.all(A[y:y + M, x:x + M] == B):
                ans = 'Yes'

    print(ans)


if __name__ == '__main__':
    main()

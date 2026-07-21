import sys
readline = sys.stdin.buffer.readline
import numpy as np
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    N = int(readline())
    A = np.array(readline().split(), np.int64)
    total = A.sum()
    X = A[:-1].cumsum()
    Y = total - X
    ans = np.abs(X-Y).min()
    print(ans)

if __name__ == '__main__':
    main()

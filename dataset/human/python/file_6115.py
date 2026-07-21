import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
import numpy as np

def main():
    N, *ABC = map(int, read().split())
    A = ABC[:N]
    B = ABC[N:2*N]
    C = ABC[2*N:]
    ans = sum(B)
    for i in range(N-1):
        if A[i] == A[i+1] - 1:
            ans += C[A[i]-1]
    print(ans)
    return

if __name__ == '__main__':
    main()

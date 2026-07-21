import sys
from collections import deque

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    S = readline().strip()
    Q = int(readline())
    
    dq = deque(S)
    flipped = False
    for _ in range(Q):
        A = readline().split()
        if A[0] == '1':
            flipped = not flipped
        elif A[1] == '1' and not flipped or A[1] == '2' and flipped:
            dq.appendleft(A[2])
        else:
            dq.append(A[2])
    
    ans = ''.join(reversed(dq) if flipped else dq)
    
    print(ans)
    return


if __name__ == '__main__':
    main()

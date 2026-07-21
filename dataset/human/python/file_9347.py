import sys
from collections import deque
import copy
def main():
    N, K = map(int, input().split())
    A = [(int(i) - 1) for i in input().split()]
    d = []
    for i in range(N):
        d.append(-1)
    d[0] = 0
    now = 0
    cycle = 0
    ans = -1
    a = 0
    flag = True
    while K > 0:
        if flag:
            if d[A[now]] == -1:
                d[A[now]] = d[now] + 1
            else:
                cycle = (d[now] + 1) - d[A[now]]
                K %= cycle
                flag = False
                if K == 0:
                    break
        K -= 1
        now = A[now]
    print(now + 1)


if __name__ == '__main__':
    main()

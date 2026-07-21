import sys
from collections import deque

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    A = [[] for _ in range(N+1)]
    for _ in range(M):
        a, b = map(int, input().split())
        A[a].append(b)
        A[b].append(a)

    q = deque()
    for a in A[1]:
        q.append(a)

    while len(q) > 0:
        a = q.popleft()
        if N in A[a]:
            return 'POSSIBLE'

    return 'IMPOSSIBLE'





if __name__ == '__main__':
    print(main())

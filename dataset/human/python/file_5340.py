from collections import deque
N, M = map(int, raw_input().split(' '))
route = [map(int, raw_input().split(' ')) for _ in xrange(M)]

A = {}
for a, b in route:
    A.setdefault(a, []).append(b)
    A.setdefault(b, []).append(a)


def bfs(A, start, end):
    visited = set()
    queue = deque()
    visited.add(start)
    queue.append((start, 0))
    while len(queue) > 0:
        a, d = queue.popleft()
        if d >= 2:
            break
        for b in A[a]:
            if b == end:
                return True
            if b not in visited:
                visited.add(b)
                queue.append((b, d+1))
    return False


if bfs(A, 1, N):
    print 'POSSIBLE'
else:
    print 'IMPOSSIBLE'

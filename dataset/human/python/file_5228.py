from collections import deque
import sys

readline = sys.stdin.readline

def main():
    N, M = map(int, readline().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, readline().split())
        a -= 1; b -= 1
        graph[a].append(b)
    check = [0] * N

    que = deque()
    cnt = 0

    que.extend(graph[0])
    flag = False
    ans = 'IMPOSSIBLE'
    while len(que) > 0:
        q = que.pop()
        for i in graph[q]:
            if i == N-1:
                ans = 'POSSIBLE'
                flag = True
                break
        if flag:
            break
    print(ans)

if __name__ == "__main__":
    main()

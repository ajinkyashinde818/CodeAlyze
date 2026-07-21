from collections import deque


def main():
    n, m = map(int, input().split())
    shuttles = [[] for _ in range(n+1)]
    for i in range(m):
        s, e = map(int, input().split())
        shuttles[s].append(e)
    d = deque(shuttles[1])
    ans = 'IMPOSSIBLE'
    while d:
        j = d.popleft()
        if n in shuttles[j]:
            ans = 'POSSIBLE'
            break
    print(ans)


if __name__ == "__main__":
    main()

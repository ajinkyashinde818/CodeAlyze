from collections import deque


def main():
    n, k = map(int, input().split())
    a = list(map(lambda x: int(x) - 1, input().split()))
    town = [[] for _ in range(n)]
    for i in range(n):
        town[i].append(a[i])
    checked = [False for _ in range(n)]
    checked[0] = True
    q = deque([0])
    loop_begin = -1
    achieve = [0]
    while q:
        now = q.pop()
        for next in town[now]:
            if not checked[next]:
                checked[next] = True
                achieve.append(next)
                q.append(next)
            else:
                loop_begin = next
    loop_idx = achieve.index(loop_begin)
    if k < loop_idx:
        print(achieve[k] + 1)
    else:
        k -= loop_idx
        achieve = achieve[loop_idx:]
        print(achieve[k % len(achieve)] + 1)


if __name__ == '__main__':
    main()

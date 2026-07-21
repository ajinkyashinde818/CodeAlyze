import sys
sys.setrecursionlimit(10**6)


def main(input, print):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    visited = [False] * n
    route = [-1] * n
    now = 0
    start = -1
    for i in range(k):
        if visited[now]:
            for j in reversed(range(i)):
                if route[j] == now:
                    start = j
                    break
            loop = i-j
            pos = (k-start) % loop
            print(route[start+pos]+1)
            return

        route[i] = now
        visited[now] = True
        now = a[now]-1

    print(now+1)


if __name__ == '__main__':
    main(sys.stdin.readline, print)

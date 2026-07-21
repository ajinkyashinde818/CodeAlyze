from collections import defaultdict


def resolve():
    n, m = list(map(int, input().split()))
    d = defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().split())
        d[a].append(b)
    if n in d[1]:
        print("POSSIBLE")
        return 0
    for i in d[1]:
        if n in d[i]:
            print("POSSIBLE")
            return 0
    print("IMPOSSIBLE")
    return 0


if __name__ == "__main__":
    resolve()

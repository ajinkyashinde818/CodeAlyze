def input():
    import sys
    return sys.stdin.readline().rstrip()


def main():
    import math
    import collections
    import itertools

    n, m = map(int, input().split())
    ships = collections.defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().split())
        ships[a].append(b)
        ships[b].append(a)
        
    for ship_1 in ships[1]:
        if n in ships[ship_1]:
            print("POSSIBLE")
            break
    else:
        print("IMPOSSIBLE")


if __name__ == '__main__':
    main()

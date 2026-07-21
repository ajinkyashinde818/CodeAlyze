from sys import stdin


def main():
    n, k = list(map(int, input().split()))
    A = list(map(int, stdin.readline().split()))
    roots = [1]
    position = 0
    for _ in range(n):
        position = A[roots[-1]-1]
        A[roots[-1]-1] = - position
        if position < 0:
            break
        roots.append(position)

    x = roots.index(-position)
    y = len(roots) - x

    if k <= x:
        print(roots[k])
    elif k > x:
        print(roots[x + ((k-x) % y)])


if __name__ == '__main__':
    main()

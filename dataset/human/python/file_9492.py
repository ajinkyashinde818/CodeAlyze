from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a = [a[i] - 1 for i in range(n)]
    next_i = 0
    seen = [-1] * n
    count = 0
    while True:
        if seen[next_i] != -1:
            start = seen[next_i]
            l = count - seen[next_i]
            break
        seen[next_i] = count
        count += 1
        next_i = a[next_i]
    if k > start:
        k = ((k - start) % l) + start
    for i in range(n):
        if seen[i] == k:
            print(i + 1)
            break


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()

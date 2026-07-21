def solve(a, k):
    a.sort()
    min_dist = k
    for i in range(len(a)):
        start = a[i]
        end = a[(i + len(a) - 1) % len(a)]
        if start > end:
            end += k
        min_dist = min(min_dist, end - start)
    return min_dist


if __name__ == "__main__":
    k, n = map(int, input().split())
    a = [int(x) for x in input().split()]
    print(solve(a, k))

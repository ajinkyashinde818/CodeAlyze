K, N = map(int, input().split(' '))
A = list(map(int, input().split(' ')))


def main(k, n, a):
    distance = []
    for i in range(n):
        dist = abs(a[i] - a[i - 1])
        if dist >= k / 2:
            dist = k - dist
        distance.append(dist)

    distance.pop(distance.index(max(distance)))

    res = sum(distance)

    return res


print(main(K, N, A))

if __name__ == '__main__':
    k, n = tuple([int(i) for i in input().split()])
    distances = [int(i) for i in input().split()]

    between = [0] * len(distances)
    between[0] = distances[0] + k - distances[-1]

    mx = 0
    for i in range(1, len(distances)):
        between[i] = distances[i] - distances[i - 1]
        mx = max(mx, between[i])

    total = sum(between)
    res = total
    for i in range(len(between)):
        res = min(res, total - between[i])

    print(res)

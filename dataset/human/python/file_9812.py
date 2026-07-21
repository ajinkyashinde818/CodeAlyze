def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    N, K = read_ints()
    A = [a-1 for a in read_ints()]
    distance = [-1]*N
    i = 0
    k = K
    while k > 0:
        if distance[i] != -1:
            cycle_length = K-k-distance[i]
            k %= cycle_length
            if k == 0:
                break
        else:
            distance[i] = K-k
        i = A[i]
        k -= 1
    return i+1


if __name__ == '__main__':
    print(solve())

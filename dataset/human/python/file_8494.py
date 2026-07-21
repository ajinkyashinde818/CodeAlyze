def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    K, N = read_ints()
    A = read_ints()
    distance = K-(A[0]+(K-A[N-1]))
    for i in range(N-1):
        distance = min(distance, K-(A[i+1]-A[i]))
    return distance


if __name__ == '__main__':
    print(solve())

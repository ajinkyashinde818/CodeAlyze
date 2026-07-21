from sys import stdin


def main():
    N, K = [int(x) for x in stdin.readline().rstrip().split()]
    As = [int(x) for x in stdin.readline().rstrip().split()]

    done = [0] * N
    step = -1
    start = 0
    current = 1
    between = 0

    while True:
        if done[current - 1] > 0:
            start = done[current - 1] - 1
            between = step - done[current - 1] + 1
            break
        step += 1
        done[current - 1] = step
        current = As[current - 1]

    if K <= step:
        print(done.index(K) + 1)
    else:
        res = (K - start) % between
        if res == 0:
            res = between
        print(done.index(res + start) + 1)


if __name__ == "__main__":
    main()

import sys

readline = sys.stdin.buffer.readline


def solver(N, K, A):
    i = 0
    i_list = [0]
    reached = [False for _ in range(N)]

    while True:
        next_i = A[i]
        if reached[next_i]:
            break

        reached[next_i] = True
        i_list.append(next_i)
        i = next_i

    m = i_list.index(next_i)

    if m >= K:
        return i_list[K] + 1

    le = len(i_list) - m
    K -= m
    ind = K % le

    return i_list[m + ind] + 1


def run():
    N, K = map(int, readline().split())
    A = list(map(int, readline().split()))
    A = [a - 1 for a in A]

    ans = solver(N, K, A)
    print(ans)


run()

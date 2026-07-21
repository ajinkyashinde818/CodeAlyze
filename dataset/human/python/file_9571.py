import sys

input = sys.stdin.readline


def main():
    N, K = map(int, input().split())
    A = list(map(lambda x: int(x) - 1, input().split()))

    route = [0]
    visited = set([0])
    now_town = 0
    while True:
        next_town = A[now_town]
        if next_town in visited:
            break
        else:
            visited.add(next_town)
            route.append(next_town)
            now_town = next_town

    loop_start = route.index(next_town)
    loop_len = len(route[loop_start:])
    count_before_loop = len(route) - loop_len
    if K <= count_before_loop:
        ans = route[K] + 1
    else:
        K -= count_before_loop
        r = K % loop_len
        ans = route[loop_start + r] + 1
    print(ans)


if __name__ == "__main__":
    main()

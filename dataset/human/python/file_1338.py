def solve(N, As):
    d = 0
    s = sum(As)
    m = 10 ** 15
    for a in As[:N - 1]:
        d += a
        m = min(m, abs(d - (s - d)))
    return abs(m)


if __name__ == "__main__":
    N = int(input())
    As = list(map(int, input().split(" ")))
    print(solve(N, As))

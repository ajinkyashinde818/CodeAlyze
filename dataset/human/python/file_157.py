def solve(R, G, B, N):
    ans = 0
    mr = N // R
    for i in range(mr + 1):
        mg = (N - i * R) // G
        for j in range(mg + 1):
            b = N - i * R - j * G
            if b % B == 0:
                ans += 1
    return ans


if __name__ == "__main__":
    R, G, B, N = map(int, input().split(" "))
    print(solve(R, G, B, N))

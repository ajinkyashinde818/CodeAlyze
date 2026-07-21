import sys

def solve():
    input = sys.stdin.readline
    R, G, B, N = map(int, input().split())
    count = 0
    for i in range(N // R + 1):
        red = R * i
        lem = N - red
        for j in range(lem // G + 1):
            green = G * j
            if (lem - green) % B == 0: count += 1
    print(count)

    return 0

if __name__ == "__main__":
    solve()

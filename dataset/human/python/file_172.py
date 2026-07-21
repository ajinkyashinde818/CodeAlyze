from sys import stdin


def main():
    R, G, B, N = [int(x) for x in stdin.readline().rstrip().split()]
    count = 0
    for r in range(3001):
        if N < r * R:
            break
        for g in range(3001):
            if N < g * G:
                break
            tmp = N - (R * r + G * g)
            if tmp < 0:
                break
            if tmp % B == 0:
                count += 1
    print(count)


if __name__ == "__main__":
    main()

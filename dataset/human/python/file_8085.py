from sys import stdin


def main():
    K, S = [int(x) for x in stdin.readline().rstrip().split()]
    result = 0
    for X in range(K + 1):
        for Y in range(K + 1):
            Z = S - (X + Y)
            if Z < 0:
                break
            if X <= K and Y <= K and Z <= K:
                result += 1
    print(result)


if __name__ == "__main__":
    main()

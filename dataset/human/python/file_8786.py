from sys import stdin


def main():
    K, N = [int(x) for x in stdin.readline().rstrip().split()]
    As = [int(x) for x in stdin.readline().rstrip().split()]
    As1 = sorted(As)
    result = As1[-1] - As1[0]
    for i in range(1, len(As1)):
        x = (As1[-1] - As1[i]) + (K - As1[-1]) + As1[i - 1]
        result = min(result, x)

    As2 = [K - a for a in As]
    As2 = sorted(As2)
    result = min(result, As2[-1] - As2[0])
    for i in range(1, len(As2)):
        x = (As2[-1] - As2[i]) + (K - As2[-1]) + As2[i - 1]
        result = min(result, x)

    print(result)


if __name__ == "__main__":
    main()

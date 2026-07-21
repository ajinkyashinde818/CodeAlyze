from sys import stdin


def main():
    _ = int(stdin.readline().rstrip())
    As = [int(x) for x in stdin.readline().rstrip().split()]
    Bs = [int(x) for x in stdin.readline().rstrip().split()]
    Cs = [int(x) for x in stdin.readline().rstrip().split()]
    result = 0
    tmp = -1
    for A in As:
        result += Bs[A - 1]
        if tmp + 1 == A:
            result += Cs[tmp - 1]
        tmp = A
    print(result)


if __name__ == "__main__":
    main()

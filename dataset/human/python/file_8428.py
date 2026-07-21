import sys


def input() -> str:
    return sys.stdin.readline().rstrip("\r\n")


def main():
    k, n = map(int, input().split())
    houses = [int(s) for s in input().split()]
    houses = houses + [houses[0] + k]
    distance = 0
    for i in range(1, len(houses)):
        distance = max(distance, houses[i] - houses[i-1])
    print(k - distance)


if __name__ == "__main__":

    main()

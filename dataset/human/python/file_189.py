from collections import defaultdict
import math


def kari():
    map(int, input().split())
    list(map(int, input().split()))
    math.ceil()

def main():
    red, green, blue, num = map(int, input().split())
    ans = 0
    for i in range(num + 1):
        for j in range(num + 1):
            nokori = num - red * i - blue * j
            if nokori < 0:
                break
            if nokori % green == 0:
                # print(i, j, nokori)
                ans += 1
        if num < red * i:
            break
    print(ans)


if __name__ == '__main__':
    main()

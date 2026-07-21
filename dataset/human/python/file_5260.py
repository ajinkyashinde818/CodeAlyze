import sys
input = sys.stdin.readline


def readstr():
    return input().strip()


def readint():
    return int(input())


def readnums():
    return map(int, input().split())


def readstrs():
    return input().split()


def main():
    N, M = readnums()
    ab = [tuple(readnums()) for _ in range(M)]
    
    al = {x[1] for x in ab if x[0] == 1}
    bl = {x[0] for x in ab if x[1] == N}
    print('POSSIBLE' if al & bl else 'IMPOSSIBLE')


if __name__ == "__main__":
    main()

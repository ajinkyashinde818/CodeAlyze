import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    x = int(readline())
    
    if x < 1200:
        print('ABC')
    else:
        print('ARC')
    
    return


if __name__ == '__main__':
    main()

import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def main():
    S = list(input())
    T = list(input())
    S.sort()
    T.sort(reverse = True)
    if S < T:
        print('Yes')
    else:
        print('No')
if __name__ == '__main__':
    main()

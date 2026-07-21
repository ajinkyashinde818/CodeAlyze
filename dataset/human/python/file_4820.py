import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    s = sorted(input())
    t = sorted(input(), reverse=True)
    S = ''.join(map(str,s))
    T = ''.join(map(str,t))
    if S<T:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()

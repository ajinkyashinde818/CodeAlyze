import sys
read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    N, K, S = map(int, readline().split())
    ans = [S]*K
    if S == 10**9:
        ans += [1]*(N-K)
    else:
        ans += [S+1]*(N-K)
    print(' '.join(map(str, ans)))

if __name__ == '__main__':
    main()

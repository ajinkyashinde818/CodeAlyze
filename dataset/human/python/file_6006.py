import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N = int(readline())
    A = list(map(int, readline().split()))
    B = list(map(int, readline().split()))
    C = list(map(int, readline().split()))
    
    ans = sum(B)
    for i in range(N-1):
        if A[i] + 1 == A[i+1]:
            ans += C[A[i] - 1]
    
    print(ans)
    return


if __name__ == '__main__':
    main()

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

def main():
    K, N = map(int, input().split())
    A = list(map(int,input().split()))

    md = 0
    ans = 0
    for i in range(N - 1):
        d = A[i+1] - A[i]
        ans += d
        md = max(md, d)

    d = (K - A[-1]) + A[0]
    ans += d
    md = max(md, d)

    ans -= md

    print(ans)



if __name__ == "__main__":
    main()

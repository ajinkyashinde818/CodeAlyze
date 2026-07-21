import sys
input = sys.stdin.readline


def main():
    N = int(input())
    A = list(map(int, input().split()))
    R = [0]
    for a in A:
        R.append(R[-1] + a)
    ans = 10**9*(2*10**5)
    for i in range(1, N):
        ans = min(ans, abs(R[N] - R[i] - R[i]))
    print(ans)


if __name__ == '__main__':
    main()

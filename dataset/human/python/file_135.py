import sys

def main():
    input = sys.stdin.readline
    R, G, B, N = map(int, input().split())
    ans = 0
    for i in range(N//R+1):
        for j in range(N//G+1):
            rest = N - R*i - G*j
            if rest >= 0 and rest % B == 0:
                ans += 1

    return ans


if __name__ == '__main__':
    print(main())

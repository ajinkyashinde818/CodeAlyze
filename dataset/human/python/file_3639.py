import sys
def main():
    input = sys.stdin.readline
    N = int(input())
    ans = 0
    for i in range(2, int(N ** 0.5) + 1):
        c = 0
        while N % i == 0:
            c += 1
            N //= i
        i = 0
        while c > i:
            ans += 1
            i += 1
            c -= i
    if N > 1:
        ans += 1
    print(ans)

if __name__ == '__main__':
    main()

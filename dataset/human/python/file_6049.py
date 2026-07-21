import sys
input = sys.stdin.readline

def main():
    N = int(input())
    a = list(map(int, input().split()))
    b =list(map(int, input().split()))
    c = list(map(int, input().split()))

    ans = b[a[0]-1]
    pre = a[0] - 1
    for i in range(1, N):
        ans += b[a[i] - 1]
        if pre + 1 == a[i] - 1:
            ans += c[pre]
        pre = a[i] - 1
    print(ans)


if __name__ == "__main__":
    main()

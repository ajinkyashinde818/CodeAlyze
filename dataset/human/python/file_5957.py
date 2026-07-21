import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = [0] + list(map(int , input().split()))
    c = [0] + list(map(int , input().split()))
    ans = 0
    for i in range(n):
        ans += b[a[i]]
        if i > 0 and a[i-1] == a[i] - 1:
            ans += c[a[i-1]]
    print(ans)

if __name__ == '__main__':
    main()

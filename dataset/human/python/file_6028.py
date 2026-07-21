import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    a, b, c = [tuple(map(int, input().split())) for i in range(3)]
    ans = 0
    pre = -2

    for i in a:
        ans += b[i-1]
        if pre + 1 == i:
            ans += c[pre-1]
        pre = i
    print(ans)

if __name__ == '__main__':
    main()
